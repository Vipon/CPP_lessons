main: main.o Stack.o
    g++ main.o Stack.o -o main

 Stack.o: Stack.cpp Stack.h
    g++ -Wall -Wextra -Werror -std=c++14 -O3 -c Stack.cpp

 main.o: main.cpp Stack.cpp
    g++ -Wall -Wextra -Werror -std=c++14 -O3 -c main.cpp

 exec: main 
    ./main

 clean: 
    rm -rf main.o Stack.o main 