#ifndef __STATE_H__
#define __STATE_H__

#include "Telegram.h"

namespace panicengine {


// each instance must be a singleton
template <typename T>
class State {

 private:
  State();
  State(const State&);
  State& operator=(const State&);

  
 public:
  virtual ~State() {}

  virtual void enter(T*) = 0;
  virtual void execute(T*) = 0;
  virtual void exit(T*) = 0;

  virtual bool onMessage(T* receiver, const Telegram &message) {
    return false;
  }

  // template<typename ChildClass>
  // static ChildClass<T>* instance() {
  //   static ChildClass<T> instance;
  //   return &instance;
  // }
  static State* instance() {
    static State instance;
    return &instance;
  }
};



} // namespace panicengine


#endif // __STATE_H__
