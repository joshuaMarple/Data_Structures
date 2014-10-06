#include "Node.h"

Node::Node(){
	leftChild = nullptr;
	rightChild = nullptr;
	data = -1;
}

Node::Node(int x, Node* l, Node* r){
	leftChild = l;
	rightChild = r;
	data = x;
}

Node::~Node(){
	
}

Node* Node::getLeftChild(){
	return leftChild;
}

Node* Node::getRightChild(){
	return rightChild;
}

void Node::setLeftChild(Node* x){
	leftChild = x;
}

void Node::setRightChild(Node* x){
	rightChild = x;
}

void Node::setData(int x){
	data = x;
}

int Node::getData(){
	return data;
}

int Node::numOfChildren(){
	int num = 0;
	if(leftChild != nullptr){
		num++;
	}
	if(rightChild != nullptr){
		num++;
	}
	return num;
}
