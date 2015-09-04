#ifndef _MESSAGEDISPATCHER_H_
#define _MESSAGEDISPATCHER_H_

#include <set>
#include "Telegram.h"
#include "Entity.h"


namespace panicengine {

class MessageDispatcher
{
 private:
  MessageDispatcher();
  MessageDispatcher(const MessageDispatcher&);
  MessageDispatcher& operator=(const MessageDispatcher&);

  std::set<Telegram> priorityQueue;

  void discharge(const Telegram &message);

 public:
  virtual ~MessageDispatcher();

  static MessageDispatcher* instance();

  void dispatchMessage(int sender,
                       int receiver,
                       std::string message,
                       double delay = 0.0,
                       void *extrainfo = NULL);

  void dispatchDelayedMessage();
};

}  // namespace panicengine

#endif /* _MESSAGEDISPATCHER_H_ */
