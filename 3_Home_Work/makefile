main: Zp_main.o Zp.o
	g++ Zp_main.o Zp.o -o main

Stack.o: Zp.cpp my_class.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c Zp.cpp

main.o: Zp_main.cpp Zp.cpp
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c Zp_main.cpp

exec: main 
	./main

clean: 
	rm -rf Zp_main.o Zp.o main 