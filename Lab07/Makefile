all:Lab07

# Lab07: main.o Queue.o Binary_search_tree.o min5heap.o
# 	g++ Queue.o BST_node.o Binary_search_tree.o min5heap.o main.o -o Lab5

Lab07: main.o
	g++ -g main.o  -o Lab7

main.o: main.cpp 
	g++ -g -c -std=c++11 main.cpp 

# min5heap.o: min5heap.cpp
# 	g++ -c -std=c++11 min5heap.cpp

# Queue.o: Queue.cpp
# 	g++ -c -g -std=c++11 Queue.cpp

# BST_node.o: BST_node.cpp
# 	g++ -c -g -std=c++11 BST_node.cpp

# Binary_search_tree.o: Binary_search_tree.cpp
# 	g++ -c -g -std=c++11 Binary_search_tree.cpp

clean:
	rm *.o ./Lab7