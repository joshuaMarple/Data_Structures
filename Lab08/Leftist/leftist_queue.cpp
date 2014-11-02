#include "leftist_queue.h"

leftist_queue::leftist_queue(){

}

leftist_queue::~leftist_queue(){
	
}

void leftist_queue::push(leftist_node* t){
	if(count == size-1){
		leftist_node** temp = new leftist_node*[size*2];
		for(int i = 0; i < size; i++){
			temp[i] = arr[i];
		}
		arr = temp;
		size = size*2;
	}
	arr[count] = t;
	count++;
}

leftist_node* leftist_queue::pop(){
	leftist_node* temp = arr[0];
	for(int i = 0; i < size-1; i++){
		arr[i] = arr[i+1];
	}
	count--;
	return temp;
}

leftist_node* leftist_queue::peek(){
	return arr[0];
}

bool leftist_queue::is_empty(){
	if(count != 0){
		return false;
	}
	return true;
}