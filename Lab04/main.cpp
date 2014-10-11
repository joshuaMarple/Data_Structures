#include <iostream>
#include <math.h>
#include "hash_table.cpp"
// #include "./open_hash/node.cpp"
#include "lin_hash_table.cpp"
#include "quad_hash_table.cpp"
#include "Timer.cpp"

#define K 600011

int main(int argc, char* argv[]){
	Timer timer; 
	hash_table*  open_hash;
	quad_hash_table* quad_hash;
	lin_hash_table* lin_hash;

	double c_hash_lin_time[4][5];
	double c_hash_quad_time[4][5];
	double o_hash_time[4][5];
	for(int i = 2; i<=5; i++){
		double load_factor = 0.1*i;
		double rand_values[(int) floor(K*load_factor)];
		for(int j = 1; j<=5; j++) {
			srand(j);
			open_hash = new hash_table(K);
			quad_hash = new quad_hash_table(K);
			lin_hash = new lin_hash_table(K);
			// std::cout << K*load_factor << std::endl;
			for(int k = 1; k<=K*load_factor; k++) {
				rand_values[k] = rand();
				// std::cout << rand_values[k] << std::endl;
				// std::cout << "test" << std::endl;
				// assign random values into an array
			}

			timer.start();
			for(int k = 1; k<=K*load_factor; k++) {
				lin_hash->insert(rand_values[k]);
				// put the random array values into the first data struct
			}
			c_hash_lin_time[i-2][j-1] = timer.stop();
			// std::cout << c_hash_lin_time[i-2][j-1] << std::endl;


			timer.start();
			for(int k = 1; k<=K*load_factor; k++) {
				quad_hash->insert(rand_values[k]);
				// put the random array values into the first data struct
			}
			c_hash_quad_time[i-2][j-1] = timer.stop();
			// std::cout << c_hash_quad_time[i-2][j-1] << std::endl;
			// save value
			// clear timer

			// start timer
			timer.start();
			for(int k = 1; k<=K*load_factor; k++) {
				open_hash->insert(rand_values[k]);
			}
			o_hash_time[i-2][j-1] = timer.stop();
			std::cout << o_hash_time[i-2][j-1] << std::endl;
			//save value
			// clear timer
		}
	}

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<\n";

	for(int i = 0; i < 4; i++) {
		double o_avg_hash_time = 0;
		double l_avg_hash_time = 0;
		double q_avg_hash_time = 0;
		for (int j = 0; j < 5; j++) {
			// std::cout << o_hash_time[i][j] << std::endl;
			o_avg_hash_time += o_hash_time[i][j];
			l_avg_hash_time += c_hash_lin_time[i][j];
			q_avg_hash_time += c_hash_quad_time[i][j];
		}
		std::cout << "Open Hash Time: " << o_avg_hash_time/5 << std::endl;
		std::cout << "Linear Closed Hash Time: " << l_avg_hash_time/5 << std::endl;
		std::cout << "Quadratic Closed Hash Time: " << q_avg_hash_time/5 << std::endl;
	}
}