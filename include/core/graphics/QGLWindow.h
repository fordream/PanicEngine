#ifndef _QGLWINDOW_H_
#define _QGLWINDOW_H_


#include <QtWidgets/QOpenGLWidget>
#include <core/vector/Vector2D.h>

namespace panicengine {


class QGLWindow : public QOpenGLWidget {
  // Q_OBJECT

 private:

  /**
   * @brief m_backgroundColor of the window
   */
  QColor m_backgroundColor;

  int m_width;
  int m_height;
  float m_aspectRatio;
  float m_originalWidth;

  /**
   * @brief m_posX the X position where to draw the image
   */
  int m_posX;
  /**
   * @brief m_posY the Y position where to draw the image
   */
  int m_posY;


  /**
   * @brief drawEllipse draws the ellipse e with nbSegment
   * @param e
   * @param nbSegment
   */
  void drawEllipse(double eX,
                   double eY,
                   double eWidth,
                   double eHeight,
                   int nbSegment = 100);

  void drawTrianlge(Vector2D &v1, Vector2D &v2, Vector2D &v3);

  /**
   * @brief updateScene called when the scene needs to be updated
   */
  void updateScene();

 public:
  explicit QGLWindow(int width, int height, QWidget *parent = 0);


 protected:
  // OpenGL callbacks
  void initializeGL() Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void resizeGL(int width, int height) Q_DECL_OVERRIDE;
};


}  // namespace panicengine

#endif /* _QGLWINDOW_H_ */
