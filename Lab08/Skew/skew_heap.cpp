#include "skew_heap.h"
#include "skew_node.h"
#include <string>

skew_heap::skew_heap() {
	root = new skew_node();
}

skew_heap::skew_heap(std::string file) {
	root = new skew_node();
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

void skew_heap::insert(int x) {
	if (root == nullptr) {
		skew_node* n_node = new skew_node(x);
		root = n_node;
		return;
	}
	if (root->is_empty()) 
		root->set_data(x);
	else {
		skew_node* n_node = new skew_node(x);
		insert(n_node);
	}
}

void skew_heap::insert(skew_node* t) {
	if (root->is_empty()) {
		root = t;
	} else {
		root = insert_helper(root, t);	
	}
}

skew_node* skew_heap::insert_helper(skew_node* a, skew_node* b) {
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
	
	a->swap();
	return a;

}

void skew_heap::deletemin() {
	if (root == nullptr)
		return;
	root = insert_helper(root->get_right_child(), root->get_left_child());
}

void skew_heap::preorder() {
	preorder_helper(root);
}

void skew_heap::preorder_helper(skew_node* t) {
	if (t != nullptr) {
		std::cout << t->get_data() << " ";
		preorder_helper(t->get_left_child());
		preorder_helper(t->get_right_child());
	}
}

void skew_heap::inorder() {
	inorder_helper(root);
}

void skew_heap::inorder_helper(skew_node* t) {
	if (t != nullptr) {
		preorder_helper(t->get_left_child());
		std::cout << t->get_data() << " ";
		preorder_helper(t->get_right_child());
	}	
}

void skew_heap::levelorder() {
	if (root == nullptr)
		return;
	skew_queue* que = new skew_queue();
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