#include <iostream>
#include <math.h>
#include "./open_hash/hash_table.cpp"
#include "Timer.cpp"

#define K 600011

int main(int argc, char* argv[]){
	Timer timer; 
	hash_table open_hash;


	double c_hash_lin_time[4][5];
	double c_hash_quad_time[4][5];
	double o_hash_time[4][5];
	for(int i = 2; i<=5; i++){
		double load_factor = 0.1*i;
		double rand_values[(int) floor(K*load_factor)];
		for(int j = 1; j<=5; j++) {
			srand(j);
			// std::cout << K*load_factor << std::endl;
			for(int k = 1; k<=K*load_factor; k++) {
				rand_values[k] = rand();
				// std::cout << rand_values[k] << std::endl;
				// std::cout << "test" << std::endl;
				// assign random values into an array
			}

			timer.start();
			for(int k = 1; k<=K*load_factor; k++) {
				// put the random array values into the first data struct
			}
			c_hash_lin_time[i-2][j-1] = timer.stop();
			// std::cout << c_hash_lin_time[i-2][j-1] << std::endl;


			timer.start();
			for(int k = 1; k<=K*load_factor; k++) {
				// put the random array values into the first data struct
			}
			c_hash_quad_time[i-2][j-1] = timer.stop();
			// std::cout << c_hash_quad_time[i-2][j-1] << std::endl;
			// save value
			// clear timer

			// start timer
			timer.start();
			for(int k = 1; k<=K*load_factor; k++) {
				
			}
			o_hash_time[i-2][j-1] = timer.stop();
			std::cout << o_hash_time[i-2][j-1] << std::endl;
			//save value
			// clear timer
		}
	}

	//output times, find avgs, etc

}