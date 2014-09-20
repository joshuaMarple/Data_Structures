// #include "node.cpp"
#include "lin_hash_table.cpp"
#include "quad_hash_table.cpp"
#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char* argv[]) {
	quad_hash_table* q;
	lin_hash_table* l;
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
        		q = new quad_hash_table(value);
        		l = new lin_hash_table(value);
        		i = 1;
        	} else {
        		l->insert(value);
        		q->insert(value);
        	}
        }
    }

	infile.close();

	std::cout << "\n\n" << "=============================\n";

	q->print();
	std::cout << "-----------------------------\n";
	std::cout << "Remove 26\n";
	q->remove(26);
	q->print();
	std::cout << "-----------------------------\n";
	std::cout << "Insert 36, insert 42\n";
	q->insert(36);
	q->insert(42);
	q->print();
	std::cout << "-----------------------------\n";
	std::cout << "contains 26? " << q->contains(26) << std::endl;
	std::cout << "contains 36? " << q->contains(36) << std::endl;

	delete q;

	std::cout << "\n\n" << "=============================\n";

	l->print();
	std::cout << "-----------------------------\n";
	std::cout << "Remove 26\n";
	l->remove(26);
	l->print();
	std::cout << "-----------------------------\n";
	std::cout << "Insert 36, insert 42\n";
	l->insert(36);
	l->insert(42);
	l->print();
	std::cout << "-----------------------------\n";
	std::cout << "contains 26? " << l->contains(26) << std::endl;
	std::cout << "contains 36? " << l->contains(36) << std::endl;

	return 0;
}
