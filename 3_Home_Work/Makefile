main:  Particle.o main.o
	g++  Particle.o main.o -o main 

matrix.o: Particle.cpp Particle.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c Particle.cpp 

main.o: Particle.cpp Particle.cpp
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c  main.cpp

clean:
	rm -f *.o main

exec: main
	./main 