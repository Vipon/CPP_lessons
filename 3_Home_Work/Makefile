main:  matrix.o main.o
	g++  matrix.o main.o -o main 

matrix.o: matrix.cpp matrix.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c matrix.cpp 

main.o: main.cpp matrix.cpp
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c  main.cpp

clean:
	rm -f *.o main

exec: main
	./main