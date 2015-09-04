#include <core/util/Entity.h>
#include <core/util/EntityManager.h>
#include <assert.h>


namespace panicengine {

void Entity::setID(int value) {
  bool available = EntityMgr->isValidID(value);
  assert(available &&
         "<PanicEngine::Entity::setID> trying to assign unavailable ID");
  m_id = value;

  EntityMgr->registerEntity(this);
}


Entity::Entity(int id) {
  setID(id);
}

Entity::~Entity() {
  EntityMgr->removeEntity(m_id);
}


int Entity::getID() const {
  return m_id;
}

} // namespace panicengine
