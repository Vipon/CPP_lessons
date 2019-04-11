CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14 -O3

all: main_Array main_vArray List_main

main_Array: main_Array.cpp Array.h my_Exception.h
	$(CXX) main_Array.cpp $(CXXFLAGS) -o main_Array

main_vArray: main_vArray.cpp vArray.h my_Exception.h
	$(CXX) main_vArray.cpp $(CXXFLAGS) -o main_vArray

List_main: List_main.cpp List.h my_Exception.h
	$(CXX) List_main.cpp $(CXXFLAGS) -o List_main

exec_all: main_Array main_vArray List_mian
	./main_Array 
	./main_vArray
	./List_main

clean:
	rm -f main_vArray.o main_vArray main_Array.o main_Array List_main.o List_main
