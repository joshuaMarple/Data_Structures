#include <iostream>
#include <math.h>
#include "Binary_search_tree.cpp"
#include "min5heap.cpp"
#include "Timer.cpp"
#include "Queue.h"
#include "BST_node.h"

int main(int argc, char* argv[]){
	Timer timer; 
	Binary_search_tree* bst = new Binary_search_tree();
	min5heap* m5h = new min5heap();

	int n = 50000;

	double BST_time[4][5];
	double min5heap_time[4][5];

	for(int i = 0; i < 4; i++){

		for(int j = 0; j < 5; j++) {
			
			int rand_values[n];

			for(int k = 0; k < n; k++) {
				rand_values[k] = rand();
			}

			delete bst;
			bst = new Binary_search_tree();
			timer.start();
			for(int k = 0; k< n; k++) {
				bst->insert(rand_values[k]);
			}
			BST_time[i][j] = timer.stop();
			std::cout << "Finished BST insert, i = " << i << std::endl;

			delete m5h;
			timer.start();
			m5h = new min5heap(rand_values, n);
			min5heap_time[i][j] = timer.stop();
			std::cout << "Finished min5heap insert, i = " << i << std::endl;

		}

		n = 2*n;

	}

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<\n";

	for(int i = 0; i < 4; i++) {
		double bst_avg_time = 0;
		double m5h_avg_time = 0;
		for (int j = 0; j < 5; j++) {
			bst_avg_time += BST_time[i][j];
			m5h_avg_time += min5heap_time[i][j];
		}
		std::cout << "BST Avg Time: " << bst_avg_time/5 << std::endl;
		std::cout << "min5heap Time: " << m5h_avg_time/5 << std::endl;
	}

	n = 50000;
	srand(1);
	float test = 0.8;
	float values[n/10];

	std::cout << "about to input vals\n";
	int rand_values[n];
	for(int k = 0; k < n; k++) {
		rand_values[k] = rand();
	}

	delete bst;
	bst = new Binary_search_tree();

	for(int k = 0; k < n; k++) {
		bst->insert(rand_values[k]);
	}

	delete m5h;
	m5h = new min5heap(rand_values, n);
	
	for(int k = 0; k < n/10; k++) {
		values[k] = rand() % 2;
	}

	for (int j = 0; j < n/10; j++) {
		if (values[j] == 0) {
			bst->delete_min();
		} else {
			bst->insert(rand());
		}
	}
	
	std::cout << "Finished bst operations" << std::endl;

	for (int j = 0; j < n/10; j++) {
		if (values[j] == 0) {
			m5h->delete_min();
		} else {
			m5h->insert(rand());
		}
	}

	std::cout << "Finished m5h operations" << std::endl;

}