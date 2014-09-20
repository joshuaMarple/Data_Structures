class lin_hash_table
{
private:
	int size;
	int counter = 0;
	node* main_list = nullptr;
public:
	lin_hash_table(int i_size);
	~lin_hash_table();
	void insert(int x);
	bool remove(int x);
	void print();
	int hash_add(int x);
	int hash_remove(int x, int i);
	bool contains(int x);
	bool isFull();
};