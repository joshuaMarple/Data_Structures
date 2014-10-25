#include "min5heap.h"

min5heap::min5heap() {
	for (int i = 0; i < 500; i++) {
		heap[i] = INT_MAX; // need to have a default value
	}
}

min5heap::min5heap(std::string input_file) {
	for (int i = 0; i < 500; i++) {
		heap[i] = INT_MAX; // need to have a default value
	}
	std::ifstream infile;
	infile.open ("data.txt");
    std::string line;
    while(std::getline(infile, line)){
        std::stringstream  lineStream(line);
        int value;
        while(lineStream >> value){
        	if (max < value)
				max = value;
        	heap[num_nodes] = value;
        	num_nodes++;
        }
    }
    infile.close();

	for (int i = num_nodes; i >= 0; i--) {
		heapify(i);
	}
}

min5heap::min5heap(int input_arr[], int size) {
	delete [] heap;
	heap = input_arr;

	num_nodes = size;
	// level_order();
	for (int i = num_nodes; i >= 0; i--) {
		heapify(i);
	}
}

bool min5heap::is_empty(){
	return num_nodes == 0;
}

void min5heap::insert(int x) {
	int parent = (num_nodes-1)/5;
	if (max < x)
		max = x;
	insert_helper(x, parent, num_nodes);
	num_nodes++;
}

bool min5heap::insert_helper(int x, int parent, int cur_loc) {
	if (parent == 0) {
		if (x < heap[parent]) {
			heap[cur_loc] = heap[parent];
			heap[parent] = x;
		}
		else {
			heap[cur_loc] = x;
		}
	} else if (x < heap[parent]) {
		heap[cur_loc] = heap[parent];
		insert_helper(x, (parent-1)/5, parent);
	} else {
		heap[cur_loc] = x;
	}
}

void min5heap::remove(int x) {
	// std::cout << num_nodes << std::endl;
	for (int i = 0; i < num_nodes; i++) {
		if (heap[i] == x) {

			if (i != num_nodes - 1) {
				heap[i] = heap[num_nodes - 1];
				heap[num_nodes-1] = INT_MAX;
				// std::cout << heap[i] << std::endl;
				// std::cout << num_nodes << std::endl;
				// std::cout << heap[num_nodes - 1] << std::endl;
				num_nodes--;
				// for (int j = num_nodes; j >= 0; j--) {
				// 	heapify(i);
				// }
			} else {
				heap[num_nodes-1] = INT_MAX;
				num_nodes--;
			}
			remove(x);
			break;
		}
	}
}

void min5heap::delete_min() {
	remove(heap[0]);
}

void min5heap::delete_max() {
	remove(max);
	max = findmax();
}

int min5heap::findmax() {
	max = 0;
	for (int i = 0; i < num_nodes; i++) {

	}
}

void min5heap::level_order() {
	int rightmost = 0;
	for(int i = 0; i < num_nodes; i++) {
		std::cout << heap[i] << " ";
		if (i%5 == 0){
			if (i == rightmost) {
				std::cout << std::endl;
				if (rightmost > 0) {
					rightmost = rightmost*rightmost+rightmost; // Square the value, add
															   // it to current location.
				} else {
					rightmost = 5;
				}
			} else {
				std::cout << "- ";
			}
		}
	}
	std::cout << "\n";
}

bool min5heap::search(int x) {
	for (int i = 0; i < num_nodes; i++) {
		if (heap[i] == x)
			return true;
	}
	return false;
}

void min5heap::heapify(int loc) {
	int min = 5*loc+1; // fill in with a default value
	if ( min < num_nodes ) {
		for(int i = 1; i <= 5; i++) {
			if (5*loc+i < num_nodes) {
				if (heap[5*loc+i] < heap[min])
					min = 5*loc+i;
			} 
		}
	} else {
		min = loc;
	}
	
	if (heap[min] < heap[loc]) {
		int tmp = heap[loc];
		heap[loc] = heap[min];
		heap[min] = tmp;
		heapify(loc);
		if (min < num_nodes) {
			heapify(min);
		}
	}
}