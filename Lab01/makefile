all:Lab01

Lab01: main.o
	g++ -g -std=c++11 main.cpp -o Lab01 && make clean

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

linked_list.o: linked_list.cpp linked_list.h node.o
	g++ -c -std=c++11 linked_list.cpp

node.o: node.cpp node.h
	g++ -c -std=c++11 node.cpp

clean:
	rm *.o
