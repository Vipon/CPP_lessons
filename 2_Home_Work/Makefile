main: main_stack02.o Stack02.o
	g++ main_stack02.o Stack02.o -o main

Stack.o: Stack02.cpp Stack02.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c Stack02.cpp

main.o: main_stack02.cpp Stack02.cpp
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c main_stack02.cpp

exec: main 
	./main

clean: 
	rm -rf main_stack02.o Stack02.o main