all:Lab08

Lab08: main.o skew_node.o skew_heap.o leftist_node.o leftist_heap.o leftist_queue.o skew_queue.o
	g++ skew_node.o skew_heap.o leftist_node.o leftist_heap.o leftist_queue.o skew_queue.o main.o -o Lab08

main.o: main.cpp 
	g++ -c -g -std=c++11 main.cpp

leftist_queue.o: ./Leftist/leftist_queue.cpp
	g++ -c -g -std=c++11 ./Leftist/leftist_queue.cpp

skew_queue.o: ./Skew/skew_queue.cpp
	g++ -c -g -std=c++11 ./Skew/skew_queue.cpp

skew_node.o: ./Skew/skew_node.cpp
	g++ -c -g -std=c++11 ./Skew/skew_node.cpp

skew_heap.o: ./Skew/skew_heap.cpp
	g++ -c -g -std=c++11 ./Skew/skew_heap.cpp

leftist_node.o: ./Leftist/leftist_node.cpp
	g++ -c -g -std=c++11 ./Leftist/leftist_node.cpp

leftist_heap.o: ./Leftist/leftist_heap.cpp
	g++ -c -g -std=c++11 ./Leftist/leftist_heap.cpp

clean:
	rm *.o