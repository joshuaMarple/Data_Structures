all: Lab11 disjoint_set_tester


Lab11: main.o disjoint_node.o disjoint_set.o min_span_tree.o
	g++ disjoint_node.o disjoint_set.o min_span_tree.o main.o  -o Lab11

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

min_span_tree.o: min_span_tree.cpp
	g++ -c -g -std=c++11 min_span_tree.cpp

disjoint_node.o: disjoint_node.cpp
	g++ -c -g -std=c++11 disjoint_node.cpp

disjoint_set.o: disjoint_set.cpp
	g++ -c -g -std=c++11 disjoint_set.cpp


# tests
disjoint_set_tester: disjoint_set_tester.o disjoint_set.o disjoint_node.o
	g++ disjoint_node.o disjoint_set.o disjoint_set_tester.o -g -std=c++11 -o disjoint_test
	./disjoint_test

disjoint_set_tester.o: disjoint_set_tester.cpp
	g++ -c -g -std=c++11 disjoint_set_tester.cpp

clean: 
	rm *.o ./Lab11 ./disjoint_test