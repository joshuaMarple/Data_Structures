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
		// std::cout << a->order() << std::endl;;
		BQ_node* t = Sub_merge(a, root[a->order()]);
		// std::cout << t->order() << std::endl;
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

}

void BQ::levelorder() {
	for (int i = 0; i < arr_size; i++) {
		if (root[i] != nullptr) {
			root[i]->levelorder();
			std::cout << "\n===========\n";
		}
	}
}
