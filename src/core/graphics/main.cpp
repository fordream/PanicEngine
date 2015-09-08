#include <QApplication>
#include <QFileDialog>
#include <opencv2/imgcodecs/imgcodecs.hpp>

#include <iostream>
#include <sys/stat.h>

#include "opencvglviewer.h"
#include "opencvfacedetect.h"

#define NB_IMAGE 3

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    std::string images[NB_IMAGE] = {"./rsrc/Loic.jpg", "./rsrc/Sylvain.jpg", "./rsrc/Nicolas.jpg"};

    std::string path;

    if (argc > 1)
    {
        int i = 0;
        bool fromFile = false;
        i = atoi(argv[1]);
        if (i == 0) // try to load an image from disk
        {
            struct stat buf;
            if (stat(argv[1], &buf) != -1)
            {
                fromFile = true;
            }
        }
        else if (i > NB_IMAGE - 1) // stay in images bounds
        {
            i = 0;
        }
        path = fromFile ? argv[1] : images[i]; // the path to load the image from
    }
    else // if no argument open a file dialog to select an image
    {
        path = QFileDialog::getOpenFileName().toStdString();
        if (path.empty())
        {
            std::cout << "cancel selected, exiting..." << std::endl;
            return 0;
        }
    }

    OpenCVGLViewer viewer;


    cv::Mat image = cv::imread(path);

    std::cout << "Face detection : " << path << ", please wait ... " << std::flush;
    SFace face;
    try
    {
        face = OpenCVFaceDetect::detectAndDraw(image, false);
    }
    catch (OpenCVFaceDetect::UnableToLoadClassifier &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    std::cout << "done" << std::endl;


    if (viewer.showImage(image, face)) // show only if showImage succeed
    {
        viewer.show();
    }

    return app.exec();

    return 0;
}



void QGLWindow::renderImage() {
  // make a (scaled) copy from m_renderedImage that will be rendered
  QImage image;

  int width = m_renderedImage.width();
  int height = m_renderedImage.height();

  // scale only if both dimensions are modified
  if (width != m_width &&
      height != m_height) {
    image = m_renderedImage.scaled(QSize(m_width, m_height),
                                   Qt::IgnoreAspectRatio,
                                   Qt::SmoothTransformation);
  }
  else {
    image = m_renderedImage;
  }

  glRasterPos2i(m_posX, m_posY);

  width = image.width();
  height = image.width();

  glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
}

void QGLWindow::renderFace() {
  // calculate the ratio of between the original image and the rendered image
  float ratio = static_cast<float>(m_width)
                /static_cast<float>(m_renderedImage.width());

  // scale and set the new origin for each ellipse
  // in order to draw it on top of the face

  drawEllipse(m_face.face.scale(ratio).setOrigin(m_posX, -m_posY));
  drawEllipse(m_face.eyes[0].scale(ratio).setOrigin(m_posX, -m_posY));
  drawEllipse(m_face.eyes[1].scale(ratio).setOrigin(m_posX, -m_posY));
  drawEllipse(m_face.smile.scale(ratio).setOrigin(m_posX, -m_posY));
}


bool QGLWindow::showImage(const cv::Mat &image, const SFace &face) {
  // get the detected face position
  m_face = SFace(face);

  // keep original image ratio
  m_ratio = static_cast<float>(image.cols)/static_cast<float>(image.rows);

  // convert the image in a Qt/OpenGL one
  if (image.channels() == 3) {
    m_renderedImage = QImage((const unsigned char*)image.data,
                             image.cols, image.rows,
                             static_cast<int>(image.step),
                             QImage::Format_RGB888);
  }
  else if (image.channels() == 1) {
    m_renderedImage = QImage((const unsigned char*)image.data,
                             image.cols, image.rows,
                             static_cast<int>(image.step),
                             QImage::Format_Indexed8);
  }
  else
    return false;  // impossible to convert the image

  // conversion needs to mirror back the image
  m_renderedImage = m_renderedImage.mirrored();


  updateScene();

  return true;
}
