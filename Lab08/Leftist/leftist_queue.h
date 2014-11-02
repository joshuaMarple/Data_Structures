#ifndef _leftist_queue_H
#define _leftist_queue_H

#include "leftist_node.h"

class leftist_queue{
	private:
		leftist_node** arr = new leftist_node*[20];
		int size = 20;
		int count = 0;
	public:
		leftist_queue();
		~leftist_queue();
		void push(leftist_node* n);
		leftist_node* pop();
		leftist_node* peek();
		bool is_empty();
};

#endif