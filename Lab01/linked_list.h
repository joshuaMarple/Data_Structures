
class linked_list
{
private:
	void printHelper(node* l);
	void insertHelper(int x, node* l);
	bool eraseHelper(int x, node* l, node* prev);
	node* findHelper(int x, node* location);
	node* head_ptr;
public:
	linked_list();
	void insert(int x);
	bool isEmpty();
	bool erase(int x);
	void print();
	node* find(int x);
};