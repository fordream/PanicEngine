#include "opencvglviewer.h"

#include <QOpenGLFunctions>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

OpenCVGLViewer::OpenCVGLViewer(QWidget *parent):
    QOpenGLWidget(parent),
    m_backgroundColor(QColor::fromRgb(150, 150, 150)),
    m_imWidth(0),
    m_imHeight(0),
    m_posX(0),
    m_posY(0),
    m_imRatio(4.0f/3.0f)
{
}



void OpenCVGLViewer::initializeGL()
{
    makeCurrent(); // make this context current

    //load OpenGL functions
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    // set background color
    float r = ((float)m_backgroundColor.darker().red())/255.0f;
    float g = ((float)m_backgroundColor.darker().green())/255.0f;
    float b = ((float)m_backgroundColor.darker().blue())/255.0f;
    f->glClearColor(r, g, b, 1.0f);

}


void OpenCVGLViewer::resizeGL(int width, int height)
{
    makeCurrent();
    glViewport(0, 0, (GLint)width, (GLint)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, width, 0, height, 0, 1);

    glMatrixMode(GL_MODELVIEW);

    // calculate the new width and height
    m_imHeight = width/m_imRatio;
    m_imWidth = width;

    if (m_imHeight > height)
    {
        m_imWidth = height*m_imRatio;
        m_imHeight = height;
    }

    // calculate the new position of the image in the window
    m_posX = (width - m_imWidth)/2;
    m_posY = (height - m_imHeight)/2;


    updateScene();
}

void OpenCVGLViewer::updateScene()
{
    if (this->isVisible())
        update();
}

void OpenCVGLViewer::paintGL()
{

    makeCurrent();

    glClear(GL_COLOR_BUFFER_BIT); // clear the current display

    if (!m_renderedImage.isNull())
    {
        glLoadIdentity();

        glPushMatrix();

        // render the image followed by the ellipses on the face
        renderImage();
        renderFace();

        glPopMatrix();

        glFlush();
    }

}

void OpenCVGLViewer::renderImage()
{
    // make a (scaled) copy from m_renderedImage that will be rendered
    QImage image;

    int width = m_renderedImage.width();
    int height = m_renderedImage.height();

    // scale only if both dimensions are modified
    if (width != m_imWidth &&
            height != m_imHeight)
    {
        image = m_renderedImage.scaled(QSize(m_imWidth, m_imHeight),
                                       Qt::IgnoreAspectRatio,
                                       Qt::SmoothTransformation);
    }
    else
    {
        image = m_renderedImage;
    }

    glRasterPos2i(m_posX, m_posY);

    width = image.width();
    height = image.width();

    glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());


}

void OpenCVGLViewer::renderFace()
{
    // calculate the ratio of between the original image and the rendered image
    float ratio = (float)m_imWidth/(float)m_renderedImage.width();
    // scale and set the new origin for each ellipse in order to draw it on top of the face
    drawEllipse(m_face.face.scale(ratio).setOrigin(m_posX, -m_posY));
    drawEllipse(m_face.eyes[0].scale(ratio).setOrigin(m_posX, -m_posY));
    drawEllipse(m_face.eyes[1].scale(ratio).setOrigin(m_posX, -m_posY));
    drawEllipse(m_face.smile.scale(ratio).setOrigin(m_posX, -m_posY));
}


bool OpenCVGLViewer::showImage(const cv::Mat &image, const SFace &face)
{
    // get the detected face position
    m_face = SFace(face);

    // keep original image ratio
    m_imRatio = (float)image.cols/(float)image.rows;

    // convert the image in a Qt/OpenGL one
    if (image.channels() == 3)
    {
        m_renderedImage = QImage((const unsigned char*)image.data,
                                 image.cols, image.rows,
                                 (int)image.step, QImage::Format_RGB888);

    }
    else if (image.channels() == 1)
    {
        m_renderedImage = QImage((const unsigned char*)image.data,
                                 image.cols, image.rows,
                                 (int)image.step, QImage::Format_Indexed8);
    }
    else
        return false; // impossible to convert the image


    m_renderedImage = m_renderedImage.mirrored(); // conversion needs to mirror back the image


    updateScene();

    return true;
}

void OpenCVGLViewer::drawEllipse(const SEllipse &e, int nbSegment)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < nbSegment; ++i)
    {
        float theta = 2.0f * 3.1415926f * (float)i/(float)nbSegment;

        float x = e.width * cosf(theta);
        float y = e.height * sinf(theta);

        glVertex2f(e.x + x, m_imHeight - e.y + y);
    }
    glEnd();
}
