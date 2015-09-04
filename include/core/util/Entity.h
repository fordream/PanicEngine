#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Telegram.h"

namespace panicengine {

class Entity {
 private:
  int m_id;

  void setID(int val);

 public:
  Entity(int id);
  virtual ~Entity();

  virtual void update() = 0;
  virtual bool handleMessage(const Telegram &message) = 0;

  int getID() const;
  
};

} // namespace panicengine


#endif /* _ENTITY_H_ */
