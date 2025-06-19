#ifndef VOCABULARY_H
#define VOCABULARY_H

#include <string>
#include <map>

class Vocabulary {
private:
    std::string fileName;
    std::map<std::string, std::string> vocData;

public:
    Vocabulary(const std::string& fileName);
    
    void printCard() const;
    void addCard();
    void removeCard();
    void queryCard() const;
    void quiz();
    bool quitProgram();
    
    const std::map<std::string, std::string>& getVocData() const { return vocData; }
};

#endif
