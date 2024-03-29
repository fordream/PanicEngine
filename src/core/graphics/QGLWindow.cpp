#include <core/graphics/QGLWindow.h>
#include <core/util/EntityManager.h>
#include <core/vector/Vector2D.h>
#include <QtGui/QOpenGLFunctions>

#include <iostream>


namespace panicengine {

QGLWindow::QGLWindow(int width, int height, QWidget *parent):
    QOpenGLWidget(parent),
    m_backgroundColor(QColor::fromRgb(150, 150, 150)),
    m_width(width),
    m_height(height),
    m_aspectRatio(static_cast<float>(width)/static_cast<float>(height)),
    m_originalWidth(width),
    m_posX(0),
    m_posY(0) {
  resize(width, height);
}



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
  if (this->isVisible()) {
    panicengine::EntityMap::const_iterator it;
    for (it = panicengine::EntityMgr->begin();
         it != panicengine::EntityMgr->end(); ++it) {
      it->second->update();
    }
    update();
  }
}


void QGLWindow::paintGL() {
  makeCurrent();

  glClear(GL_COLOR_BUFFER_BIT);  // clear the current display

  glLoadIdentity();

  glPushMatrix();

  glRasterPos2i(m_posX, m_posY);  // set origin for drawing images


  // draw the game entities
  panicengine::EntityMap::const_iterator it;
  std::cout << m_width << "/" << m_originalWidth << std::endl;
  for (it = panicengine::EntityMgr->begin();
       it != panicengine::EntityMgr->end(); ++it) {
    it->second->render(panicengine::Vector2D(m_posX, m_posY),
                       static_cast<float>(m_width)/static_cast<float>(m_originalWidth));
  }

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


void QGLWindow::drawTrianlge(Vector2D &v1,
                             Vector2D &v2,
                             Vector2D &v3) {

  // QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
  double vertices[] = {v1.x, v1.y, v2.x, v2.y, v3.x, v3.y};

  // Méthode 1
  // f->glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
  // f->glEnableVertexAttribArray(0);
  // f->glDrawArrays(GL_TRIANGLES, 0, 3);
  // f->glDisableVertexAttribArray(0);

  // Méthode 2
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_DOUBLE, 0, vertices);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableClientState(GL_VERTEX_ARRAY);

  // Méthode 3
  // glBegin(GL_TRIANGLE_FAN);
  // glVertex2f(x1, y1);
  // glVertex2f(x2, y2);
  // glVertex2f(x3, y3);
  // glEnd();
}


}  // namespace panicengine
