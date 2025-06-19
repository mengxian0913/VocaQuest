#!/bin/bash
g++ -std=c++11 -Wall -Wextra -o vocaquest main.cpp AlertMsg.cpp Log.cpp Quiz.cpp Vocabulary.cpp VocaQuestApp.cpp
echo "編譯完成！執行 ./vocaquest 來運行程式"
