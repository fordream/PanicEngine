#ifndef _TELEGRAM_H_
#define _TELEGRAM_H_

#include <string>

namespace panicengine {

struct Telegram {

  Telegram(int sender, int receiver, std::string message, void *extrainfo) :
      sender(sender),
      receiver(receiver),
      message(message),
      dispatchTime(0),
      extrainfo(extrainfo) {}


  int sender;
  int receiver;

  std::string message;

  double dispatchTime;

  void *extrainfo;

  friend bool operator<(const Telegram &t1, const Telegram &t2) {
    return t1.dispatchTime < t2.dispatchTime;
  }
};

} // namespace panicengine


#endif /* _TELEGRAM_H_ */
