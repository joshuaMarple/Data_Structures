#include "node.h"
#include <cstddef>

node::node() {
	next = nullptr;
}

node::node(int input){
	next = nullptr;
	item = input;
}

void node::setItem(const int input) {
	item = input;
}

void node::setNext(node* next_node_ptr){
	next = next_node_ptr;
}

int node::getItem() {
	return item;
}

node* node::getNext() {
	return next;
}