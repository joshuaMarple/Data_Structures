#ifndef _leftist_heap_H
#define _leftist_heap_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "leftist_node.h"
#include "leftist_queue.h"

class leftist_heap {

	private:
		leftist_node* root;
		
		leftist_node* insert_helper(leftist_node* a, leftist_node* b);
		void preorder_helper(leftist_node* t);
		void inorder_helper(leftist_node* t);

	public:
		leftist_heap();
		~leftist_heap();
		leftist_heap(std::string file);
		void inorder();
		void preorder();
		void levelorder();
		void insert(int x);
		void insert(leftist_node* t);
		void deletemin();

};

#endif