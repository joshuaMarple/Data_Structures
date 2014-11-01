#ifndef _LEFTIST_NODE_H
#define _LEFTIST_NODE_H

class Leftist_node {

	private:
		Leftist_node* left_child;
		Leftist_node* right_child;
		int data = -1;
		bool empty = true;
		int rank = 0;

	public:
		Leftist_node();
		~Leftist_node();
		Leftist_node(int x);
		bool is_empty();
		Leftist_node* get_left_child();
		Leftist_node* get_right_child();
		Leftist_node* set_left_child(Leftist_node* t);
		Leftist_node* set_right_child(Leftist_node* t);
		int get_data();
		int get_rank();
		void set_data(int x);

}