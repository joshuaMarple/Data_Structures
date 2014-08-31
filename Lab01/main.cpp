#include "node.cpp"
#include "linked_list.cpp"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	
	linked_list* l = new linked_list();

	int cur;
	std::ifstream infile;
	infile.open ("data.txt");
        while(infile >> cur) // To get you all the lines.
        {
        	l->insert(cur);
        	infile.get();	
        }
	infile.close();

	l->print();
	std::cout << "\n";

	l->insert(4);
	l->print();
	std::cout << "\n";

	l->erase(1);
	l->print();
	std::cout << "\n";

	l->insert(72);
	l->print();
	std::cout << "\n";

	l->erase(44);
	l->print();
	std::cout << "\n";

	l->insert(99);
	l->print();
	std::cout << "\n";

	l->erase(55789);
	l->print();
	std::cout << "\n";
}
