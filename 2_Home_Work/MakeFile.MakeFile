main: main.o Stack.o
    g++ main.o Stack.o -o main

 Stack.o: stack.cpp stack.h
    g++ -Wall -Wextra -Werror -std=c++14 -O3 -c stack.cpp

 main.o: main.cpp stack.cpp
    g++ -Wall -Wextra -Werror -std=c++14 -O3 -c main.cpp

 exec: main 
    ./main

 clean: 
    rm -rf main.o Stack.o main 