#include "closed_node.h"
#include <cstddef>

closed_node::closed_node() {
	used = false;
	empty = true;
}

closed_node::closed_node(int input){
	item = input;
	empty = false;
	used = true;
}

void closed_node::setItem(const int input) {
	item = input;
	empty = false;
	used = true;
}

void closed_node::removeItem() {
	item = 0;
	empty = true;
}

int closed_node::getItem() {
	return item;
}

bool closed_node::isUsed(){
	return used;
}

bool closed_node::isEmpty() {
	return empty;
}