#ifndef _BQ_H
#define _BQ_H

#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>

#include "BQ_node.h"
#include "Queue.h"

#define arr_size 50

class BQ {

	private:
		BQ_node* root[arr_size];
		Queue* child_queue = new Queue();
		Queue* sibling_queue = new Queue();
		BQ_node* Sub_merge(BQ_node* a, BQ_node* b);
		
	public:
		BQ();
		void Insert(int x);
		void Merge(BQ_node* a);
		void Deletemin();
		void levelorder();
		
};

#endif