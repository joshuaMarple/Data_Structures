#include "node.h"
#include <cstddef>

node::node() {
	used = false;
	empty = true;
}

node::node(int input){
	item = input;
	empty = false;
	used = true;
}

void node::setItem(const int input) {
	item = input;
	empty = false;
	used = true;
}

void node::removeItem() {
	item = 0;
	empty = true;
}

int node::getItem() {
	return item;
}

bool node::isUsed(){
	return used;
}

bool node::isEmpty() {
	return empty;
}