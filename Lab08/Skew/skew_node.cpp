#include "skew_node.h"
#include <algorithm>

skew_node::skew_node() {
	right_child = nullptr;
	left_child = nullptr;
}

skew_node::~skew_node(){
	if (right_child != nullptr)
		delete right_child;
	if (left_child != nullptr)
		delete left_child;
}

skew_node::skew_node(int x){
	right_child = nullptr;
	left_child = nullptr;
	data = x;
	calc_rank();
}

int skew_node::rank() {
	return cur_rank;
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
	calc_rank();
}

skew_node* skew_node::set_right_child(skew_node* t){
	right_child = t;
	calc_rank();
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

void skew_node::calc_rank() {
	if (left_child == nullptr || right_child == nullptr) {
		cur_rank = 1;
	} else {
		cur_rank = std::min(left_child->rank(), right_child->rank()) + 1;
	}
}