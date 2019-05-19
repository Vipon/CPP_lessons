main: gObject.o segment.o ellipse.o triangle.o rectangle.o main.o
	g++  gObject.o segment.o ellipse.o triangle.o rectangle.o main.o -o main 

gObject.o: gObject.cpp gObject.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c gObject.cpp 

segment.o: segment.cpp segment.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c segment.cpp 

ellipse.o: ellipse.cpp ellipse.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c ellipse.cpp

triangle.o: triangle.cpp triangle.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c triangle.cpp

rectangle.o: rectangle.cpp rectangle.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c rectangle.cpp

main.o: main.cpp segment.cpp ellipse.cpp triangle.cpp rectangle.cpp
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c  main.cpp

clean:
	rm -f *.o main

exec: main
	./main