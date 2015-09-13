#ifndef _SAMPLESCENE_H_
#define _SAMPLESCENE_H_

#include <core/graphics/Scene.h>

class SampleScene : public panicengine::Scene {
 public:
  SampleScene(QString s, int width, int height, int argc, char **argv);
  virtual bool init();
};

#endif /* _SAMPLESCENE_H_ */
