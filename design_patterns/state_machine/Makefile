.PHONY: clean all

all: build/main

#exec
build/main: build/main.o build/Automaton.o build/AutomatonFirstState.o build/AutomatonSecondState.o build/AutomatonThirdState.o
	g++ -g -std=c++14 build/main.o \
	build/Automaton.o \
	build/AutomatonFirstState.o \
	build/AutomatonSecondState.o \
	build/AutomatonThirdState.o \
	-o build/main                                                           

#src
build/main.o: src/main.cpp
	g++ -g -c src/main.cpp -o build/main.o

build/Automaton.o: src/Automaton.cpp
	g++ -g -c src/Automaton.cpp -o build/Automaton.o

build/AutomatonFirstState.o: src/AutomatonFirstState.cpp
	g++ -g -c src/AutomatonFirstState.cpp -o build/AutomatonFirstState.o

build/AutomatonSecondState.o: src/AutomatonSecondState.cpp
	g++ -g -c src/AutomatonSecondState.cpp -o build/AutomatonSecondState.o

build/AutomatonThirdState.o: src/AutomatonThirdState.cpp
	g++ -g -c src/AutomatonThirdState.cpp -o build/AutomatonThirdState.o