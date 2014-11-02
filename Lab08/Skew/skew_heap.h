#ifndef _skew_heap_H
#define _skew_heap_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "skew_node.h"
#include "skew_queue.h"

class skew_heap {

	private:
		skew_node* root;
		int cur_rank = 0;
		skew_node* insert_helper(skew_node* a, skew_node* b);
		void preorder_helper(skew_node* t);
		void inorder_helper(skew_node* t);

	public:
		skew_heap();
		~skew_heap();
		skew_heap(std::string file);
		void inorder();
		void preorder();
		void levelorder();
		void insert(int x);
		void insert(skew_node* t);
		void deletemin();

};

#endif