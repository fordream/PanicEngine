#include <core/graphics/Scene.h>

namespace panicengine {


Scene::Scene(std::string title, int width, int height, int argc, char **argv):
    m_title(title),
    m_width(width),
    m_height(height),
    m_app(argc, argv),
    m_window(0, static_cast<float>(width)/static_cast<float>(height))
{
  m_window.show();
  init();
}


bool Scene::init() {
  return true;
}


bool Scene::run() {
  return m_app.exec();
}


}
