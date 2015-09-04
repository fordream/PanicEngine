#ifndef __EVENT_DISPATCHER_H__
#define __EVENT_DISPATCHER_H__

#include "Event.h"
#include <vector>
#include <string>
#include <map>

namespace panicengine {

class EventDispatcher {
 private:
  std::map<const std::string, std::vector<eventFunctionPtr> > m_eventHandlerList;

  EventDispatcher();
  EventDispatcher(const EventDispatcher&);
  EventDispatcher& operator=(const EventDispatcher&);

 public:
  void addEventListener(const std::string &type, eventFunctionPtr listener);

  bool hasEventListener(const std::string &type);

  void dispatchEvent(const Event &event);

  void removeEventListener(const std::string &type, eventFunctionPtr listener);

  EventDispatcher* instance();

};

}

#endif
