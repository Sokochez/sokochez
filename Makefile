CXX=g++
CXXFLAGS=-W -Wall -std=c++11
LDFLAGS=
DEF=
EXEC=sokochez
SRC=$(wildcard ./src/*.cpp)
OBJ=$(SRC:.cpp=.o)
BIN=./bin/
all: $(EXEC)

sokochez: $(OBJ)
	$(CXX) -o $(BIN)$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(DEF)

.PHONY: clean mrproper install uninstall

clean:
	-rm ./src/*.o

mrproper: clean
	rm $(BIN)*

pdf:
	pdflatex -output-directory bin/ *.tex

install: sokochez
	mkdir -p $(DESTDIR)$(PREFIX)/usr/share/games/sokochez 
	cp -R maps $(DESTDIR)$(PREFIX)/usr/share/games/sokochez
	cp -R $(BIN)$(EXEC) $(DESTDIR)$(PREFIX)/usr/games/sokochez
	cp -R ./sokochez-story $(DESTDIR)$(PREFIX)/usr/games/sokochez-story

uninstall: 
	rm -rf $(DESTDIR)$(PREFIX)/usr/share/games/sokochez $(DESTDIR)$(PREFIX)/usr/games/sokochez $(DESTDIR)$(PREFIX)/usr/games/sokochez-story
