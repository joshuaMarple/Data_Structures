#include "skew_queue.h"

skew_queue::skew_queue(){

}

skew_queue::~skew_queue(){
	
}

void skew_queue::push(skew_node* t){
	if(count == size-1){
		skew_node** temp = new skew_node*[size*2];
		for(int i = 0; i < size; i++){
			temp[i] = arr[i];
		}
		arr = temp;
		size = size*2;
	}
	arr[count] = t;
	count++;
}

skew_node* skew_queue::pop(){
	skew_node* temp = arr[0];
	for(int i = 0; i < size-1; i++){
		arr[i] = arr[i+1];
	}
	count--;
	return temp;
}

skew_node* skew_queue::peek(){
	return arr[0];
}

bool skew_queue::is_empty(){
	if(count != 0){
		return false;
	}
	return true;
}