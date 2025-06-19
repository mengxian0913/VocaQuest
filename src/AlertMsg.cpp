#include "AlertMsg.h"

AlertMsg::AlertMsg(const std::string& message) {
    this->message = message;
    this->curTime = getTime();
}

std::string AlertMsg::getTime() {
    time_t now = time(0);
    return std::string(ctime(&now));
}
