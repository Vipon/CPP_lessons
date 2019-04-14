CXX=g++
CXXFLAGS=#-Wall -Wextra -Werror -std=c++14 -O3

all: testArray testvArray testList

testArray: testArray.cpp Array.h 
	$(CXX) testArray.cpp $(CXXFLAGS) -o testArray

testvArray: testvArray.cpp vArray.h 
	$(CXX) testvArray.cpp $(CXXFLAGS) -o testvArray

testList: testList.cpp List.h
	$(CXX) testList.cpp $(CXXFLAGS) -o testList

exec_all: testArray testvArray testList
	./testArray 
	./testvArray
	./testList

clean:
	rm -f testvArray.o testvArray testArray testArray.o testList testList.o