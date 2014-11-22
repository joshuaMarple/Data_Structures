#ifndef _BQ_node_H
#define _BQ_node_H

#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>

class BQ_node {

	private:
		int key = -1;
		int order_val = 0;
		BQ_node* right = nullptr;
		BQ_node* child = nullptr;

	public:
		BQ_node();
		BQ_node(int x);
		~BQ_node();
		void Append(BQ_node* a);
		int data();
		int order();
		void Set_right(BQ_node* a);
		void Set_child(BQ_node* a);
		BQ_node* get_right();
		BQ_node* get_child();
		void levelorder();
		void Child_append(BQ_node* a);
		void Sibling_append(BQ_node* a);
};

#endif