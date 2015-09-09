#include <core/util/EntityManager.h>


namespace panicengine {

EntityManager* EntityManager::instance() {
  static EntityManager instance;
  return &instance;
}


EntityManager::~EntityManager() {
  clear();
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


void EntityManager::clear() {
  for (EntityMap::iterator it = m_entityMap.begin();
       it != m_entityMap.end();
       ++it) {
    delete (it->second);
  }
}

bool EntityManager::isValidID(int id) {
  EntityMap::iterator test = m_entityMap.find(id);
  return (test == m_entityMap.end());
}


EntityMap::const_iterator EntityManager::begin() {
  return m_entityMap.begin();
}

EntityMap::const_iterator EntityManager::end() {
  return m_entityMap.end();
}


} // namespace panicengine
