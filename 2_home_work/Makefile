main.o: main.cpp
	g++ -c -Wall -Wextra -Werror -std=c++14 -O3 main.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c -Wall -Wextra -Werror -std=c++14 -O3 Stack.cpp

deniska: main.o Stack.o
	g++ -o deniska main.o Stack.o
	rm -rf main.o Stack.o
all: deniska

clean: 
	rm -rf deniska
