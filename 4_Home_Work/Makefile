CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14 -O3
LINKERFLAGS=-lSDL2

main: main.o Segment.o Triangle.o Ellipse.o Rectangle.o
	$(CXX) $^ $(LINKERFLAGS) -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< 

exec: main 
	./main

clean:
	rm -f main.o main Segment.o Triangle.o Ellipse.o Rectangle.o