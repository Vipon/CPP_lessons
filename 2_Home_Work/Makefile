all: Stack.o main.o 
	g++ ./*.o -o all
Stack.o: Stack.cpp Stack.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c Stack.cpp
main.o: main.cpp Stack.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c main.cpp
clean:
	rm -rf *.o
	rm -rf all
exec:
	./all