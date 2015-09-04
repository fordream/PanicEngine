#include <core/util/EntityManager.h>


namespace panicengine {

EntityManager* EntityManager::instance() {
  static EntityManager instance;
  return &instance;
}

void EntityManager::registerEntity(Entity *newEntity) {
  m_entityMap[newEntity->getID()] = newEntity;
}

Entity* EntityManager::getEntityFromID(int id) const {
  return m_entityMap.at(id);
}

void EntityManager::removeEntity(int id) {
  m_entityMap.erase(id);
}


bool EntityManager::isValidID(int id) {
  EntityMap::iterator test = m_entityMap.find(id);
  return (test == m_entityMap.end());
}

} // namespace panicengine
