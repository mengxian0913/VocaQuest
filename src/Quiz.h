#ifndef QUIZ_H
#define QUIZ_H

#include <map>
#include <set>
#include <vector>
#include <string>

class Quiz {
private:
    std::set<std::pair<std::string, std::string>> quiz;
    std::vector<std::pair<std::string, std::string>> vocVec;
    int amount;
    
    std::vector<std::string> getSelectOptions(const std::string& ans);

public:
    Quiz(int amount, const std::map<std::string, std::string>& vocData);
    void startQuiz();
    void printProblems() const;
};

#endif
