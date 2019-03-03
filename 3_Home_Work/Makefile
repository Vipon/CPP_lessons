all: Quaternion.o main.o 
	g++ ./*.o -o all
Quaternion.o: Quaternion.cpp Quaternion.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c Quaternion.cpp
main.o: main.cpp Quaternion.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c main.cpp
clean:
	rm -rf *.o
	rm -rf all
exec:
	./all