#include <core/util/MessageDispatcher.h>
#include <core/util/EntityManager.h>
#include <ctime>

namespace panicengine {


void MessageDispatcher::discharge(const Telegram &message) {
  Entity *pReceiver = EntityMgr->getEntityFromID(message.receiver);
  pReceiver->handleMessage(message);
}


void MessageDispatcher::dispatchMessage(int sender,
                                        int receiver,
                                        std::string message,
                                        double delay,
                                        void *extrainfo) {


  Telegram telegram(sender, receiver, message,  extrainfo);

  if (delay <= 0.0) {
    discharge(telegram);
  }
  else {
    double currentTime = time(0);  // TODO(babouchot): get current time

    telegram.dispatchTime = currentTime + delay;

    priorityQueue.insert(telegram);
  }
}


void MessageDispatcher::dispatchDelayedMessage() {
  double currentTime = time(0);

  while (priorityQueue.begin()->dispatchTime < currentTime &&
         priorityQueue.begin()->dispatchTime > 0)
  {
    const Telegram &telegram = *priorityQueue.begin();

    discharge(telegram);

    priorityQueue.erase(priorityQueue.begin());
  }
}


}  // namespace panicengine
