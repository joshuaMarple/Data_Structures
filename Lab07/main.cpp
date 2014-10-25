#include <iostream>
#include <math.h>
#include "Binary_search_tree.cpp"
#include "min5heap.cpp"
#include "Timer.cpp"
#include "Queue.h"
#include "BST_node.h"
// #include <random>

int main(int argc, char* argv[]){
	Timer timer; 
	Binary_search_tree* bst = new Binary_search_tree();
	min5heap* m5h = new min5heap();

	int n = 50000;

	double BST_time[4][5];
	double min5heap_time[4][5];

  	// std::random_device rd;
   //  std::mt19937 gen(rd());
   //  std::uniform_real_distribution<> dis(0, 1);

	// srand(n);
	// float test = rand();
	// std::cout << dis(gen) << std::endl;

	for(int i = 0; i < 4; i++){
		// double load_factor = 0.1*i;
		for(int j = 0; j < 5; j++) {
			// srand(j);
			
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

	n = 5;
	srand(1);
	float test = 0.8;
	float values[50];
	// std::cout << "about to gen vals\n";
	// for (int i = 0; i < 50; i++) {
	// 	// values[i] = dis(gen);
	// 	values[i] = rand();
	// 	std::cout << values[i] << std::endl;
	// }

	// srand(1);
	// for (int i = 0; i < .1*n; i++) {
	// 	if (values[i] < .25) {
	// 		bst->delete_min();
	// 	} else if (values[i] < .5) {
	// 		bst->delete_max();
	// 	} else if (values[i] < .75) {
	// 		bst->remove(rand());
	// 	} else {
	// 		bst->insert(rand());
	// 	}
	// }

	std::cout << "about to input vals\n";
	int rand_values[n];
	for(int k = 0; k < n; k++) {
		rand_values[k] = rand();
	}

	delete bst;
	bst = new Binary_search_tree();
	// timer.start();
	for(int k = 0; k< n; k++) {
		bst->insert(rand_values[k]);
	}
	// BST_time[i][j] = timer.stop();
	// std::cout << "Finished BST insert, i = " << i << std::endl;

	delete m5h;
	// timer.start();
	m5h = new min5heap(rand_values, n);
	// min5heap_time[i][j] = timer.stop();
	// std::cout << "Finished min5heap insert, i = " << i << std::endl;


	// int rand_values[n];

	for(int k = 0; k < 50; k++) {
		values[k] = rand() % 100;
	}

	for (int j = 0; j < 50; j++) {
		if (values[j] < 25) {
			// std::cout << values[j] << std::endl;
			std::cout << "less than 25" << std::endl;
			bst->delete_min();
		} else if (values[j] < 50) {
			std::cout << "less than 50" << std::endl;
			bst->delete_max();
		} else if (values[j] < 75) {
			std::cout << "less than 75" << std::endl;
			bst->remove(rand());
		} else {
			std::cout << "greater than 75" << std::endl;
			bst->insert(rand());
		}
	}
	
	std::cout << "Finished bst operations" << std::endl;

	for (int j = 0; j < 50; j++) {
		if (values[j] < 25) {
			// std::cout << values[j] << std::endl;
			// std::cout << "less than 25" << std::endl;
			m5h->delete_min();
		} else if (values[j] < 50) {
			// std::cout << "less than 50" << std::endl;
			m5h->delete_max();
		} else if (values[j] < 75) {
			// std::cout << "less than 75" << std::endl;
			m5h->remove(rand());
		} else {
			// std::cout << "greater than 75" << std::endl;
			m5h->insert(rand());
		}
	}
	std::cout << "Finished m5h operations" << std::endl;

}