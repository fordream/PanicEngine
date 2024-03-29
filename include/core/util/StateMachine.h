#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

#include <core/util/State.h>

namespace panicengine {


template <typename T>
class StateMachine {
 private:
  T *m_pOwner;

  State<T> *m_pCurrentState;
  State<T> *m_pPreviousState;
  State<T> *m_pGlobalState;


 public:
  explicit StateMachine(T *owner);
  virtual ~StateMachine();

  void setCurrentState(State<T> *currentState);
  void setPreviousState(State<T> *previousState);
  void setGlobalState(State<T> *globalState);

  State<T> getCurrentState() const;
  State<T> getGlobalState() const;
  State<T> getPreviousState() const;

  void update() const;

  void changeState(State<T> *pNewState);
  void revertToPreviousState();

  bool isInState(State<T> *pState) const;

  bool handleMessage(const Telegram &message);

};


}  // namespace panicengine


#endif /* _STATEMACHINE_H_ */

#include "StateMachine_impl.h"
