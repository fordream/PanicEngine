#ifndef _ENTITYMANAGER_H_
#define _ENTITYMANAGER_H_

#include <map>
#include "Entity.h"

namespace panicengine {

class EntityManager
{
 private:
  typedef std::map<int, Entity*> EntityMap;

  EntityMap m_entityMap;

  EntityManager();
  EntityManager(const EntityManager&);
  EntityManager& operator=(const EntityManager&);
  
 public:
  virtual ~EntityManager();

  static EntityManager* instance();

  void registerEntity(Entity *newEntity);

  Entity* getEntityFromID(int id) const;
  
  void removeEntity(int id);

  bool isValidID(int id);
  
};

#define EntityMgr EntityManager::instance()


#endif /* _ENTITYMANAGER_H_ */

} // namespace panicengine
