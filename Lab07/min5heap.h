#ifndef _min5heap_H
#define _min5heap_H
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>

class min5heap {

	private:
		int * heap = new int[500];
		int num_nodes = 0;
		bool search(int x);
		bool insert_helper(int x, int parent, int cur_loc);
		int findmax();
		void heapify(int i);
		int max = 0;
		
	public:
		min5heap();
		min5heap(std::string input_file);
		min5heap(int input_arr[], int size);
		bool is_empty();
		void insert(int x);
		void remove(int x);
		void delete_min();
		void delete_max();
		void level_order();
};

#endif