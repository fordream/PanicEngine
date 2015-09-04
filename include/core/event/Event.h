#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>

namespace panicengine {

struct Event {
  
  Event(const std::string &type, void *target = NULL):
      m_type(type),
      m_target(target)
  {}

  const std::string m_type;
    
  const void* m_target;
    
};

// Event function callback pointer type
typedef void (*eventFunctionPtr)(const Event &);

}  // namespace panicengine


#endif /* _EVENT_H_ */
