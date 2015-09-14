#include <core/graphics/Scene.h>


namespace panicengine {


Scene::Scene(QString title, int width, int height, int argc, char **argv):
    m_width(width),
    m_height(height),
    m_app(argc, argv),
    m_window(width, height)
{
  m_window.setWindowTitle(title);
  m_window.show();
  init();
}


bool Scene::init() {
  return true;
}


bool Scene::run() {
  if (init())
    return m_app.exec();
  else
    return false;
}


}
