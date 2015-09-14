#include "TestEntity.h"
#include <iostream>

TestEntity::TestEntity(int id, Vector2D position) : Entity(id),
                                                    m_position(position)
{
  std::cout << position << std::endl;
}

void TestEntity::update() {
  m_position += Vector2D(1, 1);
}

bool TestEntity::handleMessage(const Telegram &message) {
  std::cout << message.message << std::endl;
  return true;
}

void TestEntity::render(Vector2D positionOffset, float ratio) const {
  std::cout << m_position << "/" << ratio << std::endl;
}

