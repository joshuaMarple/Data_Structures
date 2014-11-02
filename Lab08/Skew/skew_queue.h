#ifndef _skew_queue_H
#define _skew_queue_H

#include "skew_node.h"

class skew_queue{
	private:
		skew_node** arr = new skew_node*[20];
		int size = 20;
		int count = 0;
	public:
		skew_queue();
		~skew_queue();
		void push(skew_node* n);
		skew_node* pop();
		skew_node* peek();
		bool is_empty();
};

#endif