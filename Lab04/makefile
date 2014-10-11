all:Lab04

Lab04:
	g++ -g -std=c++11 main.cpp -o lab4 -I ./open_hash/ -I ./closed_hash

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

# linked_list.o: linked_list.cpp linked_list.h node.o
# 	g++ -c -std=c++11 linked_list.cpp

# node.o: node.cpp node.h
# 	g++ -c -std=c++11 node.cpp

clean:
	rm *.o
