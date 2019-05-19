main: Stack.o main.o 
		g++ Stack.o main.o -o main


Stack.o: Stack.cpp Stack.h
		g++ -Wall -Wextra -Werror -std=c++14 -03 -c Stack.cpp


main.o: Main.cpp Stack.cpp
		g++ -Wall -Wextra -Werror -std=c++14 -03 -c main.cpp


clean:
		rm -f *.o main


exec: main
		./main	