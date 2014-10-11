class quad_hash_table
{
private:
	int size;
	int counter = 0;
	closed_node* main_list = nullptr;
public:
	quad_hash_table(int i_size);
	~quad_hash_table();
	void insert(int x);
	bool remove(int x);
	void print();
	int hash_add(int x, int i);
	int hash_remove(int x, int i);
	bool contains(int x);
	bool isFull();
};