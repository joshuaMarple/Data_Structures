#include <iostream>
#include <math.h>
#include "./Leftist/leftist_heap.h"
#include "./Skew/skew_heap.h"
#include "Timer.cpp"
#include "./Leftist/leftist_queue.h"
#include "./Skew/skew_queue.h"

int main(int argc, char* argv[]){
	Timer timer; 
	leftist_heap* left = new leftist_heap();
	skew_heap* skew = new skew_heap();

	int n = 50000;

	double BST_time[4][5];
	double skew_heap_time[4][5];

	for(int i = 0; i < 4; i++){
		std::cout << "Inserting " << n << " nodes.\n";
		for(int j = 0; j < 5; j++) {
			srand(j);
			
			int rand_values[n];

			for(int k = 0; k < n; k++) {
				rand_values[k] = rand();
			}

			delete left;
			left = new leftist_heap();
			timer.start();
			for(int k = 0; k< n; k++) {
				left->insert(rand_values[k]);
			}
			BST_time[i][j] = timer.stop();
			std::cout << "Finished leftist heap insert, time = " << BST_time[i][j] << std::endl;

			delete skew;
			timer.start();
			skew = new skew_heap();
			for(int k = 0; k < n; k++) {
				skew->insert(rand_values[k]);
			}
			skew_heap_time[i][j] = timer.stop();
			std::cout << "Finished skew heap insert, time = " << skew_heap_time[i][j] << std::endl;

		}
		n = 2*n;
	}

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<\n";
	int tmp = 50000;
	for(int i = 0; i < 4; i++) {
		double left_avg_time = 0;
		double skew_avg_time = 0;
		for (int j = 0; j < 5; j++) {
			left_avg_time += BST_time[i][j];
			skew_avg_time += skew_heap_time[i][j];
		}
		std::cout << "For n = " << tmp << std::endl;
		std::cout << "leftist heap Avg Time: " << left_avg_time/5 << std::endl;
		std::cout << "skew heap Time: " << skew_avg_time/5 << std::endl;
		tmp = tmp * 2;
	}

	n = 50000;
	srand(1);
	float test = 0.8;
	float values[n/10];

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<\n";
	
	double left_total_time = 0;
	double skew_total_time = 0;

	for(int i = 0; i < 5; i++) {

		int rand_values[n];
		for(int k = 0; k < n; k++) {
			rand_values[k] = rand();
		}

		delete left;
		left = new leftist_heap();

		for(int k = 0; k < n; k++) {
			left->insert(rand_values[k]);
		}

		delete skew;
		skew = new skew_heap();
		for(int k = 0; k < n; k++) {
			skew->insert(rand_values[k]);
		}

		for(int k = 0; k < n/10; k++) {
			values[k] = rand() % 2;
		}

		timer.start();
		for (int j = 0; j < n/10; j++) {
			if (values[j] == 1) {
				left->deletemin();
			} else {
				left->insert(rand());
			}
		}
		double cur_time = timer.stop();
		left_total_time += cur_time;
		std::cout << "BST operations complete: " << cur_time << std::endl;

		timer.start();
		for (int j = 0; j < n/10; j++) {
			if (values[j] == 1) {
				skew->deletemin();
			} else {
				skew->insert(rand());
			}
		}
		cur_time = timer.stop();
		skew_total_time += cur_time;
		std::cout << "skew_heap operations complete: " << cur_time << std::endl;
	} // end operation timing

	std::cout << "Average leftist heap operation time: " << left_total_time/5 << std::endl;
	std::cout << "Average skew heap operation time: " << skew_total_time/5 << std::endl;
} // end main