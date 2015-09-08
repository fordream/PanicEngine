#include <core/graphics/QGLWindow.h>
#include <core/util/EntityManager.h>
#include <QtGui/QOpenGLFunctions>

#include <iostream>

QGLWindow::QGLWindow(QWidget *parent, float aspectRatio):
    QOpenGLWidget(parent),
    m_backgroundColor(QColor::fromRgb(150, 150, 150)),
    m_width(0),
    m_height(0),
    m_aspectRatio(aspectRatio),
    m_originalWidth(-1),
    m_posX(0),
    m_posY(0)
{}



void QGLWindow::initializeGL() {
  makeCurrent();  // make this context current

  // load OpenGL functions
  QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
  // set background color
  float r = static_cast<float>(m_backgroundColor.darker().red())/255.0f;
  float g = static_cast<float>(m_backgroundColor.darker().green())/255.0f;
  float b = static_cast<float>(m_backgroundColor.darker().blue())/255.0f;
  f->glClearColor(r, g, b, 1.0f);
}




void QGLWindow::resizeGL(int width, int height) {

  // calculate the new width and height
  m_height = width/m_aspectRatio;
  m_width = width;

  if (m_height > height) {
    m_width = height*m_aspectRatio;
    m_height = height;
  }

  // get the original width of the window to resize the painted elements 
  if (m_originalWidth == -1)
    m_originalWidth = width;

  // calculate the new position of the image in the window
  m_posX = (width - m_width)/2;
  m_posY = (height - m_height)/2;

  makeCurrent();
  glViewport(0, 0, (GLint)width, (GLint)height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(0, width, 0, height, 0, 1);

  glMatrixMode(GL_MODELVIEW);


  updateScene();
}



void QGLWindow::updateScene() {
  if (this->isVisible())
    update();
}


void QGLWindow::paintGL() {
  makeCurrent();

  glClear(GL_COLOR_BUFFER_BIT);  // clear the current display

  glLoadIdentity();

  glPushMatrix();

  glRasterPos2i(m_posX, m_posY);  // set origin for drawing images


  // draw the games entities
  panicengine::EntityMap::const_iterator it = panicengine::EntityMgr->iterator();
  
  // drawEllipse(100, 100, 40, 40, 500);

  // render the image followed by the ellipses on the face
  // renderImage();
  // renderFace();

  glPopMatrix();

  glFlush();

}


void QGLWindow::drawEllipse(double eX,
                            double eY,
                            double eWidth,
                            double eHeight,
                            int nbSegment) {

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < nbSegment; ++i) {
    float theta = 2.0f * 3.1415926f *
                  static_cast<float>(i)/static_cast<float>(nbSegment);

    float x = eWidth * cosf(theta);
    float y = eHeight * sinf(theta);

    float ratio = m_width/m_originalWidth;

    glVertex2f(m_posX + (eX + x)*ratio, m_posY + (eY + y)*ratio);
  }
  glEnd();
}
