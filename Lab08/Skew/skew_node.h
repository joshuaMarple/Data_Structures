#ifndef _skew_NODE_H
#define _skew_NODE_H

class skew_node {

	private:
		skew_node* left_child;
		skew_node* right_child;
		int data = -1;
		bool empty = true;
		// int rank = 0;

	public:
		skew_node();
		~skew_node();
		skew_node(int x);
		bool is_empty();
		skew_node* get_left_child();
		skew_node* get_right_child();
		skew_node* set_left_child(skew_node* t);
		skew_node* set_right_child(skew_node* t);
		int get_data();
		int rank();
		void set_data(int x);

		void swap();

};

#endif