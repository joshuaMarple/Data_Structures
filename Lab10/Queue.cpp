#include "Queue.h"

Queue::Queue(){

}

Queue::~Queue(){
	
}

void Queue::push(BQ_node* t){
	if(count == size-1){
		BQ_node** temp = new BQ_node*[size*2];
		for(int i = 0; i < size; i++){
			temp[i] = arr[i];
		}
		arr = temp;
		size = size*2;
	}
	arr[count] = t;
	count++;
}

BQ_node* Queue::pop(){
	BQ_node* temp = arr[0];
	for(int i = 0; i < size-1; i++){
		arr[i] = arr[i+1];
	}
	count--;
	return temp;
}

BQ_node* Queue::peek(){
	return arr[0];
}

bool Queue::is_empty(){
	if(count != 0){
		return false;
	}
	return true;
}