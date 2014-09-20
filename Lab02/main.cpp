#include "node.cpp"
#include "hash_table.cpp"
#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char* argv[]) {
	
	hash_table* h;
	int i = 0;
	int cur;
	std::ifstream infile;
	infile.open ("data.txt");
  	std::string line;
    while(std::getline(infile, line)){
        std::stringstream  lineStream(line);
        int value;
        while(lineStream >> value){
        	if(i == 0){
        		h = new hash_table(value);
        		i = 1;
        	} else {
        		h->insert(value);
        	}
        }
    }

	infile.close();

	h->print();
	std::cout << "-----------------------------\n";
	h->remove(17);
	h->remove(14);
	h->print();
	std::cout << "-----------------------------\n";
	h->insert(2);
	h->insert(25);
	h->insert(13);
	h->print();
	std::cout << "-----------------------------\n";
	delete h;

	return 0;
}
