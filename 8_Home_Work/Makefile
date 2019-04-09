all: test_vArray.o test_Array.o
	g++ test_vArray.o -o test_vArray
	g++ test_Array.o -o test_Array
test_vArray.o: test_vArray.cpp vArray.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c test_vArray.cpp
test_Array.o: test_Array.cpp Array.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c test_Array.cpp
clean:
	rm -rf *.o
	rm -rf test_vArray test_Array
exec:
	./test_Array
	./test_vArray