.PHONY: clean all

all: build/main build/main-ut

#exec
build/main: build/main.o build/LinkedList.o
	g++ -g -std=c++14 build/main.o \
	build/LinkedList.o \
	-o build/main                                                           

build/main-ut: build/test_main.o build/LinkedListTest.o
	g++ -g -std=c++14 \
	build/test_main.o \
	build/LinkedListTest.o \
	-pthread -lgtest -lgtest_main -lgmock -lgmock_main \
	-o build/main-ut

#src
build/main.o: src/main.cpp
	g++ -g -c src/main.cpp -o build/main.o

build/LinkedList.o: src/LinkedList.cpp
	g++ -g -c src/LinkedList.cpp -o build/LinkedList.o

#gtest
build/test_main.o: test/test_main.cpp
	g++ -g -c test/test_main.cpp -o build/test_main.o 

build/LinkedListTest.o: test/LinkedListTest.cpp
	g++ -g -c test/LinkedListTest.cpp -o build/LinkedListTest.o

#clean
clean:
	rm -f build/*.o build/main build/main-ut