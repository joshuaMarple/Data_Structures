#ifndef _QUEUE_H
#define _QUEUE_H

#include "BST_node.h"

class Queue{
	private:
		BST_node** arr = new BST_node*[10];
		int size;
		int count;
	public:
		Queue();
		~Queue();
		void push(BST_node* n);
		BST_node* pop();
		BST_node* top();
		bool empty();
};

#endif