all:Lab08

Lab08: main.o Queue.o skew_node.o skew_heap.o
	g++ Queue.o skew_node.o skew_heap.o main.o -o skew

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

Queue.o: Queue.cpp
	g++ -c -g -std=c++11 Queue.cpp

skew_node.o: skew_node.cpp
	g++ -c -g -std=c++11 skew_node.cpp

skew_heap.o: skew_heap.cpp
	g++ -c -g -std=c++11 skew_heap.cpp

clean:
	rm *.o