all: test_new_vArray.o test_new_Array.o
	g++ test_new_vArray.o -o test_new_vArray
	g++ test_new_Array.o -o test_new_Array
test_new_vArray.o: test_new_vArray.cpp new_vArray.h Array_exeption.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c test_new_vArray.cpp
test_new_Array.o: test_new_Array.cpp new_Array.h Array_exeption.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c test_new_Array.cpp
clean:
	rm -rf *.o
	rm -rf test_new_vArray test_new_Array
exec:
	./test_new_Array
	./test_new_vArray