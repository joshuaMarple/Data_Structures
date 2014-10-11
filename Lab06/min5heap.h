#ifndef _MIN5HEAP_H
#define _MIN5HEAP_H
#include "heap_node.h"
#include <iostream>

class min5heap {

	private:
		int heap[500];
		int num_nodes = 0;
		
	public:
		min5heap();
		bool is_empty();
		void insert(int x);
		void remove(int x);
		void delete_min();
		void delete_max();
		void levelorder();
};

#endif