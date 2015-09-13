#include "sampleScene.h"

SampleScene::SampleScene(QString s, int width, int height,
                         int argc, char **argv) :
    panicengine::Scene(s, width, height, argc, argv) {}

bool SampleScene::init() {
  return true;
}
