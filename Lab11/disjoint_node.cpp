#include "disjoint_node.h"

disjoint_node::disjoint_node(int input) {
	data = input;
}

int disjoint_node::value() {
	return data;
}

int disjoint_node::order() {
	return order_val;
}

disjoint_node* disjoint_node::parent() {
	return parent_pointer;
}

void disjoint_node::increment_order() {
	order_val++;
}

void disjoint_node::set_parent(disjoint_node* new_parent) {
	parent_pointer = new_parent;
}