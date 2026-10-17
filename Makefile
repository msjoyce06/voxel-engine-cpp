CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O2 -Iinclude -MMD -MP

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)
DEP = $(OBJ:.o=.d)

TARGET = build/engine

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

run: all
	./build/engine

clean:
	rm -rf build

.PHONY: all run clean

-include $(DEP)
