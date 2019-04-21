CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14 -O3

main: main.cpp Array.h vArray.h
	$(CXX) $(CXXFLAGS) main.cpp -o main

exec: main
	./main

clean: 
	rm -f main.o main