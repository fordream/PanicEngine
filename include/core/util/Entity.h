#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Telegram.h"
#include "../vector/Vector2D.h"

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

  virtual void render(Vector2D positionOffset, float ratio) const = 0;
  
};

} // namespace panicengine


#endif /* _ENTITY_H_ */
