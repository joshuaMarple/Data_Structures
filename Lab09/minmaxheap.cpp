#include "minmaxheap.h"

minmaxheap::minmaxheap() {
	for (int i = 0; i < 500; i++) {
		heap[i] = INT_MAX; // need to have a default value
	}
}

minmaxheap::minmaxheap(std::string input_file) {
	for (int i = 0; i < 500; i++) {
		heap[i] = -1; // need to have a default value
	}
	std::ifstream infile;
	infile.open ("data.txt");
    std::string line;
    while(std::getline(infile, line)){
        std::stringstream  lineStream(line);
        int value;
        while(lineStream >> value){
        	heap[num_nodes] = value;
        	num_nodes++;
        }
    }
    infile.close();

	for (int i = (num_nodes-1)/2; i >= 0; i--) {
		heapify(i);
	}
}

bool minmaxheap::is_empty(){
	return num_nodes == 0;
}

bool minmaxheap::isminlevel(int location) {
	return int(trunc(log2(location+1)))%2==0;
}

void minmaxheap::insert(int x) {
	// std::cout << x << std::endl;
	heap[num_nodes] = x;
	num_nodes++;
	for (int i = (num_nodes-1)/2; i >= 0; i--) {
		heapify(i);
	}

	// int parent = (num_nodes-1)/2;
	// int grandparent = (((num_nodes-1)/2)-1)/2;
	// insert_helper(x, parent, num_nodes);
	// heapify(int(trunc(log2(parent))));
	// heapify(int(trunc(log2(num_nodes))));
}

bool minmaxheap::insert_helper(int x, int parent, int cur_loc) {
	// grandparent = 
	if (isminlevel(cur_loc)) {
		if (x < heap[parent]) {
			heap[cur_loc] = heap[parent];
			insert_helper(x, (parent-1)/2, parent);
		} else {
			heap[cur_loc] = x;
		}
	} else {
		if (x > heap[parent]) {
			heap[cur_loc] = heap[parent];
			insert_helper(x, (parent-1)/2, parent);
		} else {
			heap[cur_loc] = x;
		}
	}
}

void minmaxheap::remove(int x) {
	for (int i = 0; i <= num_nodes; i++) {
		if (heap[i] == x) {
			if (i != num_nodes - 1) {
				heap[i] = heap[num_nodes - 1];
				heap[num_nodes-1] = INT_MAX;
				num_nodes--;
				for (int i = (num_nodes-1)/2; i >= 0; i--) {
					heapify(i);
				}
			} else {
				heap[num_nodes-1] = INT_MAX;
				num_nodes--;
			}
			break;
		}
	}
}

void minmaxheap::delete_min() {
	remove(heap[0]);
}

void minmaxheap::delete_max() {
	remove(std::max(heap[1], heap[2]));
}

void minmaxheap::level_order() {
	int rightmost = 0;
	for(int i = 0; i < num_nodes; i++) {
		std::cout << heap[i] << " ";
		if (i%2 == 0){
			if (i == rightmost) {
				std::cout << std::endl;
				if (rightmost > 0) {
					rightmost = rightmost*rightmost+rightmost; // Square the value, add
															   // it to current location.
				} else {
					rightmost = 2;
				}
			} else {
				std::cout << "- ";
			}
		}
	}
	std::cout << "\n";
}

bool minmaxheap::search(int x) {
	for (int i = 0; i < num_nodes; i++) {
		if (heap[i] == x)
			return true;
	}
	return false;
}

void minmaxheap::heapify(int loc) {
	int comp = 2*loc+1; // fill in with a default value
	if (2*loc+1 >= num_nodes)
		return;

	for(int i = 1; i <= 2; i++) {
		if (isminlevel(loc)) {
			if (heap[2*loc+i] < heap[comp]) {
				if (2*loc+i < num_nodes) 
					comp = 2*loc+i;
			}
			for(int j = 1; j <= 2; j++) {
				if (heap[2*(2*loc+i)+j] < heap[comp]) {
					if (2*(2*loc+i)+j < num_nodes)
						comp = 2*(2*loc+i)+j;
				}
			}
		} else {
			if (heap[2*loc+i] > heap[comp]) {
				if (2*loc+i < num_nodes) 
					comp = 2*loc+i;
			}
			for(int j = 1; j <= 2; j++) {
				if (heap[2*(2*loc+i)+j] > heap[comp]) {
					if (2*(2*loc+i)+j < num_nodes)
						comp = 2*(2*loc+i)+j;
				}
			}
		}
	}

	if (isminlevel(loc)) {
		if (heap[comp] < heap[loc]) {
			int tmp = heap[loc];
			heap[loc] = heap[comp];
			heap[comp] = tmp;
			heapify(loc);
			heapify(comp);
		}
	} else {
		if (heap[comp] > heap[loc]) {
			int tmp = heap[loc];
			heap[loc] = heap[comp];
			heap[comp] = tmp;
			heapify(loc);
			heapify(comp);
		}
	}
}