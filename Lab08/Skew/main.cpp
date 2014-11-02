#include "skew_heap.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	skew_heap* heap = new skew_heap("data.txt");
	
	std::cout << "..........................................................\n" <<
	"Please choose one of the following commands:\n" <<
	"1- insert\n" << 
	"2- deletemin\n" << 
	"3- preorder\n" <<
	"4- inorder\n" <<
	"5- levelorder\n" << 
	"6- exit\n";
	int input;
	std::cin >> input;
	
	while(input != 6){
		if(input == 1){
			std::cout << "Which number would you like to insert?\n";
			std::cin >> input;
			heap->insert(input);
		}else if(input == 2){
			heap->deletemin();
		}else if(input == 3){
			heap->preorder();
		}else if(input == 4){
			heap->inorder();
		}else if(input == 5){
			heap->levelorder();
		}
		std::cout << "..........................................................\n" <<
		"Please choose one of the following commands:\n" <<
		"1- insert\n" << 
		"2- deletemin\n" << 
		"3- preorder\n" <<
		"4- inorder\n" <<
		"5- levelorder\n" << 
		"6- exit\n";
		std::cin >> input;
	}
		
	
	return 0;
}