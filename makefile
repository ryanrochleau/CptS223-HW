prog: main.o
	./a.out

main.o: 
	g++ -g -Wall -std=c++11 main.cpp Destination.cpp TestListMyJosephus.cpp TestVectorMyJosephus.cpp Destination.hpp VectorMyJosephus.hpp ListMyJosephus.hpp
