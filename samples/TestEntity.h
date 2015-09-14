#ifndef _TESTENTITY_H_
#define _TESTENTITY_H_


#include <core/util/Entity.h>

using namespace panicengine;

class TestEntity : Entity {
 private:
  Vector2D m_position;

 public:
  TestEntity(int id, Vector2D position);
  
  virtual void update();
  virtual bool handleMessage(const Telegram &message);
  virtual void render(Vector2D positionOffset, float ratio) const;
  
  
};


#endif /* _TESTENTITY_H_ */
