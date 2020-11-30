.PHONY: clean all

all: build/main build/main-ut

#exec
build/main: build/main.o build/Automaton.o build/AutomatonFirstState.o build/AutomatonSecondState.o build/AutomatonThirdState.o build/Context.o
	g++ -g -std=c++14 build/main.o \
	build/Automaton.o \
	build/AutomatonFirstState.o \
	build/AutomatonSecondState.o \
	build/AutomatonThirdState.o \
	build/Context.o \
	-o build/main                                                           

build/main-ut: build/test_main.o build/AutomatonTest.o
	g++ -g -std=c++14 \
	build/test_main.o \
	build/AutomatonTest.o \
	-pthread -lgtest -lgtest_main -lgmock -lgmock_main \
	-o build/main-ut

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

build/Context.o: src/Context.cpp
	g++ -g -c src/Context.cpp -o build/Context.o

build/ConcreteFirstState.o: src/ConcreteFirstState.cpp
	g++ -g -c src/ConcreteFirstState.cpp -o build/ConcreteFirstState.o

build/ConcreteSecondState.o: src/ConcreteSecondState.cpp
	g++ -g -c src/ConcreteSecondState.cpp -o build/ConcreteSecondState.o

#gtest
build/test_main.o: test/test_main.cpp
	g++ -g -c test/test_main.cpp -o build/test_main.o 

build/AutomatonTest.o: test/AutomatonTest.cpp
	g++ -g -c test/AutomatonTest.cpp -o build/AutomatonTest.o

#clean
clean:
	rm -f build/*.o build/main build/main-ut