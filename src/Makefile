CXX = /opt/homebrew/bin/g++-14
CXXFLAGS = -std=c++14 -Wall -Wextra -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
TARGET = vocaquest
SOURCES = main.cpp AlertMsg.cpp Log.cpp Quiz.cpp Vocabulary.cpp VocaQuestApp.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean
