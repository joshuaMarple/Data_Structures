#include "leftist_heap.h"
#include "leftist_node.h"
#include <string>

leftist_heap::leftist_heap() {
	root = new leftist_node();
}

leftist_heap::leftist_heap(std::string file) {
	root = new leftist_node();
	std::ifstream infile;
	infile.open ("data.txt");
    std::string line;
    while(std::getline(infile, line)){
        std::stringstream  lineStream(line);
        int value;
        while(lineStream >> value){
        	insert(value);
        }
    }
    infile.close();
}

leftist_heap::~leftist_heap() {
	delete root;
}

void leftist_heap::insert(int x) {
	if (root == nullptr) {
		leftist_node* n_node = new leftist_node(x);
		root = n_node;
		return;
	}
	if (root->is_empty()) 
		root->set_data(x);
	else {
		leftist_node* n_node = new leftist_node(x);
		insert(n_node);
	}
}

void leftist_heap::insert(leftist_node* t) {
	if (root->is_empty()) {
		root = t;
	} else {
		root = insert_helper(root, t);	
	}
}

leftist_node* leftist_heap::insert_helper(leftist_node* a, leftist_node* b) {
	if (a == nullptr) {
		return b;
	} else if (b == nullptr) {
		return a;
	} else {
		if (a->get_data() > b->get_data()) {
			return insert_helper(b, a);
		} else {
			if (a->get_right_child() == nullptr) {
				a->set_right_child(b);
			} else {
				a->set_right_child(insert_helper(a->get_right_child(), b));
			}
		}
	}

	if(a->get_left_child() == nullptr) {
		a->swap();
	} else {
		if (a->get_left_child()->rank() < a->get_right_child()->rank()) {
			a->swap();
		}
	}
	return a;

}

void leftist_heap::deletemin() {
	if (root == nullptr)
		return;
	root = insert_helper(root->get_right_child(), root->get_left_child());
}

void leftist_heap::preorder() {
	preorder_helper(root);
}

void leftist_heap::preorder_helper(leftist_node* t) {
	if (t != nullptr) {
		std::cout << t->get_data() << " ";
		preorder_helper(t->get_left_child());
		preorder_helper(t->get_right_child());
	}
}

void leftist_heap::inorder() {
	inorder_helper(root);
}

void leftist_heap::inorder_helper(leftist_node* t) {
	if (t != nullptr) {
		preorder_helper(t->get_left_child());
		std::cout << t->get_data() << " ";
		preorder_helper(t->get_right_child());
	}	
}

void leftist_heap::levelorder() {
	if (root == nullptr)
		return;
	leftist_queue* que = new leftist_queue();
	que->push(root);
	while(!que->is_empty()) {
		std::cout << que->peek()->get_data() << " ";
		if (que->peek()->get_left_child() != nullptr)
			que->push(que->peek()->get_left_child());
		if (que->peek()->get_right_child() != nullptr)
			que->push(que->peek()->get_right_child());
		que->pop();
	}
}