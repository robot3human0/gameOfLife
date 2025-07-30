CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17
LDFLAGS = -lncurses
TARGET = game_of_life
SOURCES = main.cc life.cc
HEADERS = life.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
