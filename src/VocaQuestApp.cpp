#include "VocaQuestApp.h"
#include "Log.h"
#include <iostream>
#include <cstdlib>

VocaQuestApp::VocaQuestApp(const std::string& fileName) : vocabulary(fileName) {}

void VocaQuestApp::printRules() const {
    std::cout << "1. 新增單字卡片\n";
    std::cout << "2. 打印所有卡片\n";
    std::cout << "3. 刪除單字卡片\n";
    std::cout << "4. 查詢單字卡片\n";
    std::cout << "5. 開始考試\n";
    std::cout << "6. 結束程式（保存資料｜退出）\n";
    std::cout << "7. 查詢系統狀態\n";
}

void VocaQuestApp::processUserInput(int mode) {
    switch(mode) {
        case 1:
            vocabulary.addCard();
            break;
        case 2:
            vocabulary.printCard();
            break;
        case 3:
            vocabulary.removeCard();
            break;
        case 4:
            vocabulary.queryCard();
            break;
        case 5:
            vocabulary.quiz();
            break;
        case 7:
            log.printAllLog();
            break;
    }
}

void VocaQuestApp::run() {
    std::string userInput;
    
    while(true) {
        system("clear");
        printRules();
        std::cout << "輸入選單模式： ";
        std::cin >> userInput;
        
        int mode = -1;
        if (userInput.size() != 1) continue;
        mode = userInput[0] - '0';
        
        if (mode == 6) {
            bool status = vocabulary.quitProgram();
            if (status) break;
        } else if (mode >= 1 && mode <= 7) {
            processUserInput(mode);
        } else {
            continue;
        }

        if (mode != 7) {
            std::cout << log.getNewLog();
        }

        if (mode != 6) {
            std::cout << "... press enter to continue";
            getchar();
            getchar();
        }
    }
}
