#ifndef VOCAQUESTAPP_H
#define VOCAQUESTAPP_H

#include "Vocabulary.h"

class VocaQuestApp {
private:
    Vocabulary vocabulary;
    
    void printRules() const;
    void processUserInput(int mode);

public:
    VocaQuestApp(const std::string& fileName);
    void run();
};

#endif
