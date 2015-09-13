#include "sampleScene.h"

SampleScene::SampleScene(int argc, char **argv) :
    panicengine::Scene("Sample Scene", 800, 600, argc, argv) {}


bool SampleScene::init() {
  return true;
}
