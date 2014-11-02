#include <iostream>
#include <math.h>
#include "./Leftist/leftist_heap.h"
#include "./Skew/skew_heap.h"
#include "Timer.cpp"
#include "./Leftist/leftist_queue.h"
#include "./Skew/skew_queue.h"

int main(int argc, char* argv[]){
	Timer timer; 
	leftist_heap* leftist = new leftist_heap();
	skew_heap* skew = new skew_heap();

	int n = 50000;

	double leftist_time[4][5];
	double skew_heap_time[4][5];

	for(int i = 0; i < 4; i++){

		for(int j = 0; j < 5; j++) {
			
			int rand_values[n];

			for(int k = 0; k < n; k++) {
				rand_values[k] = rand();
			}

			delete leftist;
			leftist = new leftist_heap();
			timer.start();
			for(int k = 0; k< n; k++) {
				leftist->insert(rand_values[k]);
			}
			leftist_time[i][j] = timer.stop();
			std::cout << "Finished leftist insert, i = " << i << std::endl;

			delete skew;
			timer.start();
			for(int k = 0; k< n; k++) {
				skew->insert(rand_values[k]);
			}
			skew_heap_time[i][j] = timer.stop();
			std::cout << "Finished skew_heap insert, i = " << i << std::endl;

		}

		n = 2*n;

	}

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<\n";

	for(int i = 0; i < 4; i++) {
		double leftist_avg_time = 0;
		double skew_avg_time = 0;
		for (int j = 0; j < 5; j++) {
			leftist_avg_time += leftist_time[i][j];
			skew_avg_time += skew_heap_time[i][j];
		}
		std::cout << "leftist Avg Time: " << leftist_avg_time/5 << std::endl;
		std::cout << "skew_heap Time: " << skew_avg_time/5 << std::endl;
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

	delete leftist;
	leftist = new leftist_heap();

	for(int k = 0; k < n; k++) {
		leftist->insert(rand_values[k]);
	}

	delete skew;
	skew = new skew_heap();
	for(int k = 0; k< n; k++) {
		skew->insert(rand_values[k]);
	}
	
	for(int k = 0; k < n/10; k++) {
		values[k] = rand() % 2;
	}

	for (int j = 0; j < n/10; j++) {
		if (values[j] == 0) {
			leftist->deletemin();
		} else {
			leftist->insert(rand());
		}
	}
	
	std::cout << "Finished leftist operations" << std::endl;

	for (int j = 0; j < n/10; j++) {
		if (values[j] == 0) {
			skew->deletemin();
		} else {
			skew->insert(rand());
		}
	}

	std::cout << "Finished skew operations" << std::endl;

}