all:Lab02

Lab02: main.o
	g++ -g -std=c++11 main.cpp -o lab2 && make clean

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

linked_list.o: linked_list.cpp linked_list.h node.o
	g++ -c -std=c++11 linked_list.cpp

node.o: node.cpp node.h
	g++ -c -std=c++11 node.cpp

hash_table.o: hash_table.cpp hash_table.h
	g++ -c -std=c++11 hash_table.cpp

clean:
	rm *.o
