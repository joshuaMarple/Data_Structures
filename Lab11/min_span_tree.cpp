#include "min_span_tree.h"

min_span_tree::min_span_tree(std::string filename) {

	// int length = 0;
	std::ifstream infile;
	infile.open(filename);
    std::string line;
	std::getline(infile, line);

	for (int i = 0; i < atoi(line.c_str()); i++) {

		std::cout << "=========================\n";
		std::getline(infile, line);
		length = atoi(line.c_str());
		// std::cout << 
		adj_mat = new int*[length];
		for (int j = 0; j < length; j++) {
			adj_mat[j] = new int[length];
		}
		// int adj_mat[length][length];

		for (int j = 0; j < length; j++) {

			std::getline(infile, line);
			char* new_char = strtok((char *)line.c_str(), " ");
			int k = 0;

			do {
				if (new_char != NULL) {
					adj_mat[j][k] = atoi(new_char);
					k++;
				}
				std::cout << new_char << " ";
				new_char = strtok(NULL, " ");
				
			} while(new_char != nullptr);
			std::cout << std::endl;
		}
		// std::cout << "=========================\n";
		
		// for (int j = 0; j < length; j++) {
		// 	for (int k = 0; k < length; k++) {
		// 		std::cout << adj_mat[j][k] << " ";
		// 	}
		// 	std::cout << std::endl;
		// }

		build_queue();
		kruskal();
	}
	
}

void min_span_tree::build_queue() {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			edge e;
			if(adj_mat[i][j] != 0) {
				e.a = i; e.b = j; e.cost = adj_mat[i][j];
				// std::cout << e.a << ", " << e.b << "\n";
				pq.push(e);
			}
			
		}
	}
	// while(!pq.empty()) {
	// 	std::cout << "(" << pq.top().a << " , " << pq.top().b << " , " << pq.top().cost << ")\n";
	// 	pq.pop();
	// }

}

void min_span_tree::kruskal() {
	edge mst[length-1];
	int cur_size = 0;
	disjoint_set ds(length);
	while(cur_size < (length - 1)) {
		if (ds.node_union(pq.top().a, pq.top().b)) {
			mst[cur_size] = pq.top();
			cur_size++;
		}
		pq.pop();
	}
	for(int i = 0; i < length-1; i++) {
		std::cout << "(" << mst[i].a << " , " << mst[i].b << " , " << mst[i].cost << ")\n"; 
	}

}



