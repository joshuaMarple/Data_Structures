#include "disjoint_set.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
	disjoint_set disjoint(5);
	std::cout << "Starting disjoint set tests\n";
	std::cout << "====================================================\n";
	if (disjoint.node_union(0,4) != true)
		std::cout << "error merging 0,4\n";
	if (disjoint.node_union(4,0) != false)
		std::cout << "error merging 4,0\n";
	if (disjoint.node_union(4,2) != true)
		std::cout << "error merging 4,2\n";
	if (disjoint.node_union(3,1) != true)
		std::cout << "error merging 3,1\n";
	if (disjoint.node_union(2,1) != true)
		std::cout << "error merging 2,1\n";
	if (disjoint.node_union(3,2) != false)
		std::cout << "error merging 3,2\n";
	std::cout << "Tests Complete\n";
	return 0;
}