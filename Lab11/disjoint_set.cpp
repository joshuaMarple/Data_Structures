#include "disjoint_set.h"

disjoint_set::disjoint_set(int input) {
	length = input;
	data = new disjoint_node*[input];
	for (int i = 0; i < length; i++) {
		data[i] = new disjoint_node(i);
	}
}

disjoint_set::~disjoint_set() {
	delete data;
}

bool disjoint_set::node_union(int node_a, int node_b) {
	if (data[node_a]->order() < data[node_b]->order()) {
		return node_union(node_b, node_a);
	} else {
		if (find(node_a) == find(node_b)) {
			return false;
		} else {
			if (data[node_b]->order() == data[node_a]->order()) 
				data[node_a]->increment_order();
			find(node_b)->set_parent(find(node_a));
			return true;

		}
	}
}

disjoint_node* disjoint_set::find(int input) {
	if (input < length) {
		int cur_index = input;
		disjoint_node* cur_parent = data[cur_index];
		while(data[cur_index]->parent() != nullptr) {
			cur_parent = data[cur_index]->parent();
			cur_index = cur_parent->value();
		}
		return cur_parent;
	} else
		return nullptr;
}