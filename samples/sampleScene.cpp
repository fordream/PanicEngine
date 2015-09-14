#include "sampleScene.h"

#include "TestEntity.h"

SampleScene::SampleScene(int argc, char **argv) :
    panicengine::Scene("Sample Scene", 800, 600, argc, argv) {}


bool SampleScene::init() {
  for (int i = 0; i < 10; ++i) {
    TestEntity *test = new TestEntity(i, Vector2D(i, i));
  }
  return true;
}
