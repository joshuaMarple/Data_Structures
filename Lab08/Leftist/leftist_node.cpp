#include "leftist_node.h"
#include <algorithm>

leftist_node::leftist_node() {
	right_child = nullptr;
	left_child = nullptr;
}

leftist_node::~leftist_node(){
	if (right_child != nullptr)
		delete right_child;
	if (left_child != nullptr)
		delete left_child;
}

leftist_node::leftist_node(int x){
	right_child = nullptr;
	left_child = nullptr;
	data = x;
	calc_rank();
}

int leftist_node::rank() {
	return cur_rank;
	
}

leftist_node* leftist_node::get_right_child() {
	return right_child;
}

leftist_node* leftist_node::get_left_child() {
	return left_child;
}

bool leftist_node::is_empty(){
	return data == -1;
}

leftist_node* leftist_node::set_left_child(leftist_node* t){
	left_child = t;
	calc_rank();
}

leftist_node* leftist_node::set_right_child(leftist_node* t){
	right_child = t;
	calc_rank();
}

int leftist_node::get_data(){
	return data;
}

void leftist_node::set_data(int x){
	data = x;
}

void leftist_node::swap() {
	leftist_node* tmp = left_child;
	left_child = right_child;
	right_child = tmp;
}

void leftist_node::calc_rank() {
	if (left_child == nullptr || right_child == nullptr) {
		cur_rank = 1;
	} else {
		cur_rank = std::min(left_child->rank(), right_child->rank()) + 1;
	}
}