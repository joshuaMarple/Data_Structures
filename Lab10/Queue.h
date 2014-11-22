#ifndef _QUEUE_H
#define _QUEUE_H

#include "BQ_node.h"

class Queue{
	private:
		BQ_node** arr = new BQ_node*[20];
		int size = 20;
		int count = 0;
	public:
		Queue();
		~Queue();
		void push(BQ_node* n);
		BQ_node* pop();
		BQ_node* peek();
		bool is_empty();
};

#endif