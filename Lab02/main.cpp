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

	std::cout << "Initial file loaded: ";
	l->print();
	std::cout << "\n\n";

	std::cout << "Inserted item: ";
	l->insert(4);
	l->print();
	std::cout << "\n\n";

	std::cout << "Erased item: ";
	l->erase(1);
	l->print();
	std::cout << "\n\n";

	std::cout << "Inserted item: ";
	l->insert(72);
	l->print();
	std::cout << "\n\n";

	std::cout << "Erased item: ";
	l->erase(44);
	l->print();
	std::cout << "\n\n";

	std::cout << "Inserted item: ";
	l->insert(99);
	l->print();
	std::cout << "\n\n";

	std::cout << "Erased item: ";
	l->erase(55789);
	l->print();
	std::cout << "\n\n";

	delete l;

	return 0;
}
