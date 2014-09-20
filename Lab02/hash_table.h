class hash_table
{
private:
	int size;
	linked_list* main_list = nullptr;
public:
	hash_table(int i_size);
	~hash_table();
	void insert(int x);
	bool remove(int x);
	void print();
	int hash(int x);
	bool find(int x);
};