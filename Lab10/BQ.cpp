#include "BQ.h"

BQ::BQ() {
	for(int i = 0; i<50; i++) {
		root[i] = nullptr;
	}
}

void BQ::Insert(int x) {
	BQ_node* t = new BQ_node(x);
	Merge(t);
}

void BQ::Merge(BQ_node* a) {
	if (root[a->order()] != nullptr) {
		int cur_order = a->order();
		BQ_node* t = Sub_merge(a, root[a->order()]);
		Merge(t);
		root[cur_order] = nullptr;
	} else 
		root[a->order()] = a;
}

BQ_node* BQ::Sub_merge(BQ_node* a, BQ_node* b) {
	if (a->data() < b->data()) {
		a->Child_append(b);
		return a;
	} else {
		b->Child_append(a);
		return b;
	}
}

void BQ::Deletemin() {
	BQ_node* min = nullptr;
	for (int i = 0; i < arr_size; i++) {
		if (min == nullptr) {
			if (root[i] != nullptr)
				min = root[i];
		} else {
			if (root[i] != nullptr) {
				// std::cout << min->data() << " : " << root[i]->data() << std::endl;
				if (root[i]->data() < min->data())
					min = root[i];
			}
		}
	}

	if (min == nullptr)
		return;

	for (int i = 0; i < arr_size; i++) {
		if (root[i] == min)
			root[i] = nullptr;
	}

	BQ_node* tmp = min->get_child();
	BQ_node* next_tmp = nullptr;
	while(tmp != nullptr) {
		next_tmp = tmp->get_right();
		tmp->Set_right(nullptr);
		Merge(tmp);
		tmp = next_tmp;
	}
}

// void BQ::levelorder() {
// 	for (int i = 0; i < arr_size; i++) {
// 		if (root[i] != nullptr) {
// 			root[i]->levelorder();
// 			std::cout << "\n===========\n";
// 		}
// 	}
// }

void BQ::levelorder() {
	for (int i = 0; i < arr_size; i++) {
		if(root[i] != nullptr) {
			std::cout << root[i]->data() << std::endl;
			if (root[i]->get_child() != nullptr)
				sibling_queue->push(root[i]->get_child());
			while (!sibling_queue->is_empty()) {
				std::cout << sibling_queue->peek()->data() << " ";
				if (sibling_queue->peek()->get_child() != nullptr)
					child_queue->push(sibling_queue->peek()->get_child());
				if (sibling_queue->peek()->get_right() != nullptr)
					sibling_queue->push(sibling_queue->peek()->get_right());
				sibling_queue->pop();
				if (sibling_queue->is_empty() && !child_queue->is_empty()) {
					std::cout << std::endl;
					sibling_queue = child_queue;
					child_queue = new Queue();
				}
			}
			std::cout << "\n===================\n";
		}
	}
}