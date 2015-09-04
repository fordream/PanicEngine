#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>

namespace panicengine {

class Event {
public:
    Event(const std::string &type): m_type(type) {
    }

    const std::string m_type;
    /*
        const void* target;
    */
};

// Event function callback pointer type
typedef void (*eventFunctionPtr)(const Event &);

}  // namespace panicengine


#endif /* _EVENT_H_ */
