all:Lab10

Lab10: main.o BQ.o BQ_node.o Queue.o
	g++ Queue.o BQ.o BQ_node.o main.o -o Lab10

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

BQ.o: BQ.cpp BQ_node.o Queue.o
	g++ -c -g -std=c++11 BQ.cpp

BQ_node.o: BQ_node.cpp
	g++ -c -g -std=c++11 BQ_node.cpp

Queue.o: Queue.cpp
	g++ -c -g -std=c++11 Queue.cpp

clean:
	rm *.o ./Lab10