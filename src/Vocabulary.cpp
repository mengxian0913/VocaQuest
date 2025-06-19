#include "Vocabulary.h"
#include "Quiz.h"
#include "Log.h"
#include <iostream>
#include <fstream>

Vocabulary::Vocabulary(const std::string& fileName) {
    this->fileName = fileName;
    
    std::fstream ifs(fileName, std::ios::in);
    
    if (!ifs.good()) {
        log.push("檔案開啟失敗!");
        std::cout << "檔案開啟失敗!\n";
        return;
    }

    std::string eng, zh;
    while(ifs >> eng >> zh) {
        if (vocData.count(eng) && vocData[eng] != zh) {
            log.push("資料庫資料異常");
            std::cout << "資料庫資料異常";
            return;
        }
        vocData[eng] = zh;
    }
    ifs.close();
}

void Vocabulary::printCard() const {
    std::cout << "單字卡 " << fileName << "\n";
    for(const auto& card : vocData) { 
        std::cout << card.first << " " << card.second << "\n";
    } 
    log.push("打印單字");
}

void Vocabulary::addCard() {
    std::string eng, zh;
    std::cout << "請輸入英文： ";
    std::cin >> eng;
    std::cout << "請輸入中文： ";
    std::cin >> zh;
    
    if (vocData.count(eng) && vocData[eng] != zh) {
        log.push("插入失敗( 資料庫已有資料，無法對應 )");
        std::cout << "插入失敗( 資料庫已有資料，無法對應 )";
        return;
    }

    vocData[eng] = zh;
    log.push("插入成功");
}

void Vocabulary::removeCard() {
    std::string eng;
    std::cout << "請輸入欲刪除英文單字: ";
    std::cin >> eng;

    auto it = vocData.find(eng);

    if (it == vocData.end()) {
        log.push("刪除 " + eng + " 失敗( 單字不在資料庫 )");
        return;
    }

    vocData.erase(it);
    log.push("刪除 " + eng + " 成功!");
}

void Vocabulary::queryCard() const {
    std::string eng;
    std::cout << "請輸入英文單字： ";
    std::cin >> eng;
    std::cout << "查詢結果：\n";
    
    if (!vocData.count(eng)) {
        log.push("查無 " + eng + " 此單字！");
        return;
    }

    std::cout << "英文: " << eng << "\n";
    std::cout << "中文: " << vocData.at(eng) << "\n";
    log.push("成功查詢 " + eng + " 單字");
}

void Vocabulary::quiz() {
    int amount = 0;
    std::cout << "請輸入題數(最少 1 題 | 最多 " << vocData.size() << " 題): ";
    std::cin >> amount;
    
    if (amount < 0 || amount > vocData.size()) {
        log.push("題目數量異常");
        return;
    }

    log.push("考試開始！");
    Quiz newQuiz(amount, vocData);
    newQuiz.startQuiz();
    log.push("考試結束！");
}

bool Vocabulary::quitProgram() {
    std::string ss;
    std::cout << "確定要退出程式嗎？(yes/no): ";
    std::cin >> ss;
    
    if (ss == "no" || ss == "No" || ss == "nO" || ss == "NO") return false;
    
    std::fstream ofs(fileName, std::ios::out | std::ios::trunc);
    if (!ofs.good()) {
        log.push("結束失敗！");
        std::cout << "結束失敗！\n";
        return false;
    }
    
    for(const auto& card : vocData) {
        ofs << card.first << " " << card.second << "\n";
    }

    ofs.close();
    std::cout << "退出成功！\n";
    return true;
}
