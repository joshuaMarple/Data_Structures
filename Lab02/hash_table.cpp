#include <cstddef>
#include <iostream>
#include "linked_list.cpp"
#include "hash_table.h"

hash_table::hash_table(int i_size){
	size = i_size;
	main_list = new linked_list[size];

	// for(int i = 0; i<size; i++){
	// 	main_list[i] = new linked_list();
	// }
}

hash_table::~hash_table(){
	delete [] main_list;
}

void hash_table::insert(int x){
	main_list[hash(x)].insert(x);
}

int hash_table::hash(int x){
	return x % size;
}

bool hash_table::remove(int x){
	return main_list[hash(x)].erase(x);
}

void hash_table::print(){
	for(int i = 0; i < size; i++){
		std::cout << i << ": ";
		main_list[i].print();
		std::cout << "\n";
	}
}

bool hash_table::find(int x){
	if(main_list[hash(x)].find(x) != nullptr)
		return true;
	else
		return false;
}

