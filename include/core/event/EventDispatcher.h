#ifndef __EVENT_DISPATCHER_H__
#define __EVENT_DISPATCHER_H__

#include "Event.h"
#include <vector>

namespace panicengine {

class EventDispatcher {
 public:
  void addEventListener(const std::string &type, eventFunctionPtr listener);

  bool hasEventListener(const std::string &type);

  void dispatchEvent(const Event &event);

  void removeEventListener(const std::string &type, eventFunctionPtr listener);

 private:
  std::map<const std::string, std::vector<eventFunctionPtr > > m_eventHandlerList;
};

}

#endif
