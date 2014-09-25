#ifndef _NODE
#define _NODE

class node
{
private: 
	int item;
	node* next;
public:
	node();
	node(int input);
	void setItem(const int input);
	void setNext(node* next_node_ptr);
	int getItem();
	node* getNext();
}; //end class node


#endif