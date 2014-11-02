#include "skew_node.h"
#include <algorithm>

skew_node::skew_node() {
	right_child = nullptr;
	left_child = nullptr;
}

skew_node::~skew_node(){
	data = -1;
	delete right_child;
	delete left_child;
}

skew_node::skew_node(int x){
	right_child = nullptr;
	left_child = nullptr;
	data = x;
}

int skew_node::rank() {
	if (left_child == nullptr || right_child == nullptr) {
		return 1;
	} else {
		return std::min(left_child->rank(), right_child->rank()) + 1;
	}
	
}

skew_node* skew_node::get_right_child() {
	return right_child;
}

skew_node* skew_node::get_left_child() {
	return left_child;
}

bool skew_node::is_empty(){
	return data == -1;
}

skew_node* skew_node::set_left_child(skew_node* t){
	left_child = t;
}

skew_node* skew_node::set_right_child(skew_node* t){
	right_child = t;
}

int skew_node::get_data(){
	return data;
}

void skew_node::set_data(int x){
	data = x;
}

void skew_node::swap() {
	skew_node* tmp = left_child;
	left_child = right_child;
	right_child = tmp;
}
