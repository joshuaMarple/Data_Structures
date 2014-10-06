#include "Queue.h"

Queue::Queue(){
	size = 10;
	count = 0;
}

Queue::~Queue(){
	
}

void Queue::push(BST_node* n){
	if(count == size-1){
		BST_node** temp = new BST_node*[size*2];
		for(int i = 0; i < size; i++){
			temp[i] = arr[i];
		}
		arr = temp;
		size = size*2;
	}
	arr[count] = n;
	count++;
}

BST_node* Queue::pop(){
	BST_node* temp = arr[0];
	for(int i = 0; i < size-1; i++){
		arr[i] = arr[i+1];
	}
	count--;
	return temp;
}

BST_node* Queue::top(){
	return arr[0];
}

bool Queue::empty(){
	if(count != 0){
		return false;
	}
	return true;
}