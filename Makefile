CXX=g++
CXXFLAGS=-W -Wall --std=c++11
LDFLAGS=
EXEC=sokochez
SRC=$(wildcard ./src/*.cpp)
OBJ=$(SRC:.cpp=.o)
BIN=./bin/
all: $(EXEC)

sokochez: $(OBJ)
	$(CXX) -o $(BIN)$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper

clean:
	+rm ./src/*.o

mrproper: clean
	rm $(BIN)*
