CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14 -O3

all: testArray testvArray

testArray: testArray.cpp Array.h 
	$(CXX) testArray.cpp $(CXXFLAGS) -o testArray

testvArray: testvArray.cpp vArray.h 
	$(CXX) testvArray.cpp $(CXXFLAGS) -o testvArray

exec_all: testArray testvArray
	./testArray 
	./testvArray

clean:
	rm -f testvArray.o testvArray testArray testArray.o