all:Lab08

Lab08: main.o leftist_queue.o leftist_node.o leftist_heap.o
	g++ leftist_queue.o leftist_node.o leftist_heap.o main.o -o leftist

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

leftist_queue.o: leftist_queue.cpp
	g++ -c -g -std=c++11 leftist_queue.cpp

leftist_node.o: leftist_node.cpp
	g++ -c -g -std=c++11 leftist_node.cpp

leftist_heap.o: leftist_heap.cpp
	g++ -c -g -std=c++11 leftist_heap.cpp

clean:
	rm *.o