#ifndef _leftist_NODE_H
#define _leftist_NODE_H

class leftist_node {

	private:
		leftist_node* left_child;
		leftist_node* right_child;
		int data = -1;
		bool empty = true;
		int cur_rank = 0;
		void calc_rank();

	public:
		leftist_node();
		~leftist_node();
		leftist_node(int x);
		bool is_empty();
		leftist_node* get_left_child();
		leftist_node* get_right_child();
		leftist_node* set_left_child(leftist_node* t);
		leftist_node* set_right_child(leftist_node* t);
		int get_data();
		int rank();
		void set_data(int x);

		void swap();

};

#endif