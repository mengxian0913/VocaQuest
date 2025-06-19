#include "Log.h"

Log log; // 全域實例定義

void Log::push(const std::string& msg) {
    AlertMsg newMsg(msg);
    logs.push_back(newMsg);
}

void Log::printAllLog() const {
    for(const AlertMsg& logMsg : logs) {
        std::cout << ">  " << logMsg.getMessage() << " " << logMsg.getCurTime() << "\n";
    }
}

std::string Log::getNewLog() const {
    if (logs.size() > 0) {
        return logs.rbegin()->getMessage() + "  |  " + logs.rbegin()->getCurTime();
    }
    return "還沒有 Log 的紀錄\n";
}
