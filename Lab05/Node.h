#ifndef _NODE_H
#define _NODE_H

class Node{
private:
	Node* leftChild;
	Node* rightChild;
	int data;
public:
	Node();
	Node(int x, Node* l, Node* r);
	~Node();
	Node* getLeftChild();
	Node* getRightChild();
	void setLeftChild(Node* x);
	void setRightChild(Node* x);
	void setData(int x);
	int getData();
	int numOfChildren();
};

#endif