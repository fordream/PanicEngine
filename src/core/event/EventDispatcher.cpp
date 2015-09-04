#include <core/event/EventDispatcher.h>


namespace panicengine {

void EventDispatcher::addEventListener(const std::string &type,
                                       eventFunctionPtr listener) {
    // Set the event listener to the key
    m_eventHandlerList[type].push_back(listener);
}

bool EventDispatcher::hasEventListener(const std::string &type) {
    return (m_eventHandlerList.find(type) != m_eventHandlerList.end());
}

void EventDispatcher::dispatchEvent(const Event &event) {
    // Leave if no event registered
    if (!hasEventListener(event.m_type))
        return;

    // A reference to keep code clean
    std::vector<eventFunctionPtr > &allFunctions =
        m_eventHandlerList[event.m_type];

    // Iterate through all functions in the event and execute them
    for (std::vector<eventFunctionPtr>::iterator i =
             allFunctions.begin(); i != allFunctions.end(); ++i) {
        (*i)(event);
    }
}

void EventDispatcher::removeEventListener(const std::string &type,
                                          eventFunctionPtr listener) {
  if (hasEventListener(type)) {
    std::vector<eventFunctionPtr>& listeners = m_eventHandlerList[type];
    for (std::vector<eventFunctionPtr>::iterator it =
             listeners.begin();
         it != listeners.end(); ++it) {
      
      if (*it == listener) {
        m_eventHandlerList[type].erase(it);
        break;
      }
      
    }
  }
}

}  // namespace panicengine
