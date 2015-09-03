#include <core/event/EventDispatcher.h>

namespace panicengine {

void EventDispatcher::addEventListener(const std::string &type, eventFunctionPtr listener)
{
    // Set the event listener to the key
    m_eventHandlerList[type].push_back(listener);
}

bool EventDispatcher::hasEventListener(const std::string &type)
{
    return (m_eventHandlerList.find(type) != m_eventHandlerList.end());
}

void EventDispatcher::dispatchEvent(const Event &event)
{
    // Leave if no event registered
    if (!hasEventListener(event.type))
        return;

    // A reference to keep code clean
    std::list<eventFunctionPtr > &allFunctions = m_eventHandlerList[event.type];

    // Iterate through all functions in the event and execute them
    for (std::list<eventFunctionPtr >::iterator i = allFunctions.begin(); i != allFunctions.end(); ++i) {
        (*i)(event);
    }
}

void EventDispatcher::removeEventListener(const std::string &type, eventFunctionPtr listener)
{
    if (hasEventListener(type))
        eventHandlerList[type].remove(listener);
}

}