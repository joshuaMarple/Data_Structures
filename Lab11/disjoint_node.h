#ifndef _disjoint_node_h
#define _disjoint_node_h

#include <stdlib.h>

class disjoint_node {
	private:
		int data = 0;
		disjoint_node* parent_pointer = nullptr;
		int order_val = 0;
	public:
		disjoint_node(int input);
		int value();
		int order();
		disjoint_node* parent();
		void set_parent(disjoint_node* new_parent);
		void increment_order();
};

#endif