#ifndef _disjoint_set_h
#define _disjoint_set_h

#include <stdlib.h>
#include <iostream>
#include "disjoint_node.h"

class disjoint_set {
	private:
		int length = 0;
		disjoint_node** data;
	public:
		disjoint_set();
		disjoint_set(int length);
		~disjoint_set();
		bool node_union(int node_a, int node_b);
		disjoint_node* find(int input);
};

#endif
