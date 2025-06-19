#include "Quiz.h"
#include "Log.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

Quiz::Quiz(int amount, const std::map<std::string, std::string>& vocData) {
    this->amount = amount;
    this->vocVec = std::vector<std::pair<std::string, std::string>>(vocData.begin(), vocData.end());

    while(quiz.size() < amount) {
        int randomIdx = rand() % (vocVec.size());
        std::pair<std::string, std::string> newQ = vocVec[randomIdx]; 
        if (!quiz.count(newQ)) {
            quiz.insert(newQ);
        } 
    }
}

void Quiz::startQuiz() { 
    int problemId = 1;
    int correctAmount = 0;
    
    for(auto it = quiz.begin(); it != quiz.end(); it++, problemId++) {
        system("clear");
        printf("題號:  %d  |  (答對：%d | 已完成: %d)\n\n\n", problemId, correctAmount, problemId);
        std::vector<std::string> options = getSelectOptions(it->second);
        int userChoose;

        std::cout << "請選擇 " + it->first + " 的中文：\n\n";

        for(int i = 0; i < options.size(); i++) {
            std::cout << "(" << i + 1 << "): " << options[i] << "\n\n";
        }

        std::cout << "你的選擇： ";
        std::cin >> userChoose;

        if (options[userChoose - 1] != it->second) {
            std::cout << "> " << options[userChoose - 1]  << " | " << it->second << "\n";
            std::cout << "答錯了！ 正確答案為: " << it->second << "\n";
        } else {
            std::cout << "答對了！！\n";
            correctAmount++;
        }
        
        std::cout << "... press enter to continue";
        getchar();
        getchar();
    }
}

std::vector<std::string> Quiz::getSelectOptions(const std::string& ans) {
    std::set<std::string> options{ans};
    const int amountOfOptions = 4;

    while(options.size() < amountOfOptions) {
        int randomIdx = rand() % vocVec.size();
        if (!options.count(vocVec[randomIdx].second)) {
            options.insert(vocVec[randomIdx].second);
        }
    }

    std::vector<std::string> optionVec(options.begin(), options.end());
    return optionVec;
}

void Quiz::printProblems() const {
    for(const auto& q : quiz) {
        std::cout << q.first << " " << q.second << "\n";
    }
}
