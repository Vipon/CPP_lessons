all: gObject.o main.o gEllipse.o gRectangle.o gSegment.o gSircle.o gSquare.o gTriangle.o
	g++ ./*.o -o all
gEllipse.o: gObject.h gEllipse.h 
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c gEllipse.cpp
gRectangle.o: gRectangle.h gObject.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c gRectangle.cpp
gSegment.o: gSegment.h gRectangle.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c gSegment.cpp
gSircle.o: gSircle.h gObject.h gEllipse.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c gSircle.cpp
gSquare.o: gSquare.h gRectangle.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c gSquare.cpp
gTriangle.o: gTriangle.h gObject.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c gTriangle.cpp
gObject.o: gObject.cpp gObject.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c gObject.cpp
main.o: main.cpp gObject.h
	g++ -Wall -Wextra -Werror -std=c++14 -O3 -c main.cpp
clean:
	rm -rf *.o
	rm -rf all
exec:
	./all