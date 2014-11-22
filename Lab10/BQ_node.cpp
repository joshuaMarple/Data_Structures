#include "BQ_node.h"

BQ_node::BQ_node() {
	key = -1;
	order_val = 0;
}

BQ_node::BQ_node(int x) {
	key = x;
	order_val = 0;
}

BQ_node::~BQ_node() {
	if (child != nullptr)
		delete child;
	if (right != nullptr)
		delete right;
}

void BQ_node::Set_right(BQ_node* a) {
	right = a;
}

void BQ_node::Set_child(BQ_node* a) {
	child = a;
}

BQ_node* BQ_node::get_child() {
	return child;
}

BQ_node* BQ_node::get_right() {
	return right;
}

int BQ_node::data() {
	return key;
}

int BQ_node::order() {
	return order_val;
}

void BQ_node::levelorder() {
	if (key != -1)
		std::cout << key << ",";
	if (right != nullptr)
		right->levelorder();
	else 
		std::cout << "\n";
	if (child != nullptr)
		child->levelorder();
}

void BQ_node::Child_append(BQ_node* a) {
	if (child != nullptr)
		child->Sibling_append(a);
	else
		child = a;
	order_val=a->order()+1;
}

void BQ_node::Sibling_append(BQ_node* a) {
	if (right != nullptr) 
		right->Sibling_append(a);
	else
		right = a;
}