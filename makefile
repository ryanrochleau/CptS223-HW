prog: main.o
	./a.out

main.o: 
	g++ -g -Wall -std=c++11 main.cpp TwitterData.cpp TwitterData.hpp
