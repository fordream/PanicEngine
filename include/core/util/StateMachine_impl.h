#ifndef _STATEMACHINE_IMPL_H_
#define _STATEMACHINE_IMPL_H_

namespace panicengine {
namespace core {
namespace util {


template <typename T>
StateMachine<T>::StateMachine(T *owner) :
    m_pOwner(owner),
    m_pCurrentState(NULL),
    m_pPreviousState(NULL),
    m_pGlobalState(NULL)
{}

template <typename T>
void StateMachine<T>::setCurrentState(State<T> *currentState) {
  m_pCurrentState = currentState;
}


template <typename T>
void StateMachine<T>::setGlobalState(State<T> *globalState) {
  m_pGlobalState = globalState;
}

template <typename T>
void StateMachine<T>::setPreviousState(State<T> *previousState) {
  m_pPreviousState = previousState;
}

template <typename T>
State<T> StateMachine<T>::getCurrentState() const {
  return m_pCurrentState;
}

template <typename T>
State<T> StateMachine<T>::getGlobalState() const {
  return m_pGlobalState;
}

template <typename T>
State<T> StateMachine<T>::getPreviousState() const {
  return m_pPreviousState;
}


template <typename T>
void StateMachine<T>::update() const {
  if (m_pGlobalState) m_pGlobalState->execute(m_pOwner);

  if (m_pCurrentState) m_pCurrentState->execute(m_pOwner);
}

template <typename T>
void StateMachine<T>::changeState(State<T> *pNewState) {
  m_pPreviousState = m_pCurrentState;
  m_pCurrentState->exit(m_pOwner);

  m_pCurrentState = pNewState;
  m_pCurrentState->enter(m_pOwner);
}

template <typename T>
void StateMachine<T>::revertToPreviousState() {
  changeState(m_pPreviousState);
}

template <typename T>
bool StateMachine<T>::isInState(State<T> *pState) const {
  return (pState == m_pCurrentState);
}

}  // namespace util

}  // namespace core

}  // namespace panicengine


#endif /* _STATEMACHINE_IMPL_H_ */




