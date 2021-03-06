#include <cstddef>
#include <iostream>
#include "node.cpp"
#include "lin_hash_table.h"

lin_hash_table::lin_hash_table(int i_size){
	size = i_size;
	main_list = new node[size];
}

lin_hash_table::~lin_hash_table(){
	delete [] main_list;
}

void lin_hash_table::insert(int x){
	if (!isFull()){
		if(!contains(x)) {
			main_list[hash_add(x)].setItem(x);
			counter++;
		}
	}
}

int lin_hash_table::hash_add(int x){
	if (main_list[x % size].isEmpty()) {
		return x % size;
	} else {
		return hash_add(x+1);
	}
}

int lin_hash_table::hash_remove(int x, int i){
	if (main_list[i % size].isUsed()) {
		if(main_list[i % size].getItem() == x){
			return i % size;
		} else {
			return hash_remove(x, i+1);
		}
	} else {
		return -1;
	}
}

bool lin_hash_table::remove(int x){
	int index = hash_remove(x, x);
	if (index == -1)
		return false;
	else 
		main_list[index].removeItem();
}

void lin_hash_table::print(){
	for(int i = 0; i < size; i++){
		std::cout << i << ": ";
		if(!main_list[i].isEmpty())
			std::cout << main_list[i].getItem();
		std::cout << "\n";
	}
}

bool lin_hash_table::contains(int x){
	return hash_remove(x, x) != -1;
}

bool lin_hash_table::isFull() {
	return counter == size;
}

