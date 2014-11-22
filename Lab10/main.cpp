#include "BQ.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>


int main(int argc, char* argv[]) {

	BQ* bq = new BQ();

	std::ifstream infile;
	infile.open ("data.txt");
    std::string line;
    while(std::getline(infile, line)){
        std::stringstream  lineStream(line);
        int value;
        while(lineStream >> value){
        	bq->Insert(value);
        }
    }
    infile.close();


	std::cout << "..........................................................\n" <<
	"Please choose one of the following commands:\n" <<
	"1- insert\n" << 
	"2- deletemin\n" << 
	"3- levelorder\n" << 
	"4- exit\n";
	int input;
	std::cin >> input;
	
	while(input != 4){
			if(input == 1){
			std::cout << "Which number would you like to insert?\n";
			std::cin >> input;
			bq->Insert(input);
		}else if(input == 2){	
			// bq->deletemin();
		}else if(input == 3){
			bq->levelorder();
		}
		std::cout << "..........................................................\n" <<
		"Please choose one of the following commands:\n" <<
		"1- insert\n" << 
		"2- deletemin\n" << 
		"3- levelorder\n" << 
		"4- exit\n";
		std::cin >> input;
	}
		
	
	return 0;

}