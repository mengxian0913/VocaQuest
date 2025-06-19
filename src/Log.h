#ifndef LOG_H
#define LOG_H

#include "AlertMsg.h"
#include <vector>
#include <iostream>

class Log {
private:
    std::vector<AlertMsg> logs;

public:
    void push(const std::string& msg);
    void printAllLog() const;
    std::string getNewLog() const;
};

// 全域 log 實例
extern Log log;

#endif
