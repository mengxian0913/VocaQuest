#ifndef ALERTMSG_H
#define ALERTMSG_H

#include <string>
#include <ctime>

class AlertMsg {
private:
    std::string message;
    std::string curTime;
    
    std::string getTime();

public:
    AlertMsg(const std::string& message);
    
    std::string getMessage() const { return message; }
    std::string getCurTime() const { return curTime; }
};

#endif
