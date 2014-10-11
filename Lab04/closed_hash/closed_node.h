// #ifndef _NODE
// #define _NODE

class closed_node
{
private: 
	int item = 0;
	bool used = false;
	bool empty = true;
public:
	closed_node();
	closed_node(int input);
	void setItem(const int input);
	bool isUsed();
	int getItem();
	void removeItem();
	bool isEmpty();
};


// #endif