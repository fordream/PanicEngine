#ifndef _SCENE_H_
#define _SCENE_H_

#include <string>
#include <QtWidgets/QApplication>

#include "QGLWindow.h"

namespace panicengine {

class Scene {
 public:
  Scene(std::string title, int width, int height, int argc, char **argv);
  virtual ~Scene() {}

  virtual bool init();
  bool run();

 private:
  std::string m_title;
  int m_width;
  int m_height;


  QApplication m_app;
  QGLWindow m_window;};

}

#endif /* _SCENE_H_ */
