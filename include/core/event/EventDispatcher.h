#ifndef __EVENT_DISPATCHER_H__
#define __EVENT_DISPATCHER_H__

namespace panicengine {

class EventDispatcher
{
public:
    void addEventListener(const std::string &type, eventFunctionPtr listener);

    bool hasEventListener(const std::string &type);

    void dispatchEvent(const Event &event);

    void removeEventListener(const std::string &type, eventFunctionPtr listener);

private:
    std::map<const std::string, std::list<eventFunctionPtr > > m_eventHandlerList;
};

}

#endif