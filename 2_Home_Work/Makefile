main:  Stack.o main.o
	g++  Stack.o main.o -o main 

Stack.o: Stack.cpp Stack.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c Stack.cpp 

main.o: main.cpp Stack.cpp
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c  main.cpp

clean:
	rm -f Stack.o main main.o

exec: main
	./main 