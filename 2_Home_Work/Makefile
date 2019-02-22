CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14 -O3

EXAMPLE=Stack

main: main.o $(EXAMPLE).o
	$(CXX) $^ -o $@

$(EXAMPLE): %: %.cpp
	$(CXX) $(CXXFLAGS) -c $< 

exec: main 
	./main

clean:
	rm -f main.o main $(EXAMPLE).o