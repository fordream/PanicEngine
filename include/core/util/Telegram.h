#ifndef _TELEGRAM_H_
#define _TELEGRAM_H_

#include <string>

namespace panicengine {

struct Telegram {
  int sender;
  int receiver;

  std::string message;

  double dispatchTime;

  void *extrainfo;
};

} // namespace panicengine


#endif /* _TELEGRAM_H_ */
