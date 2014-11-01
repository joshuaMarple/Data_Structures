

Leftist_node::Leftist_node() {
	rank = 0;
	right_child = nullptr;
	left_child = nullptr;
}

Leftist_node::~Leftist_node(){
	rank = 0;
	data = -1;
	delete right_child;
	delete left_child;

}

Leftist_node::Leftist_node(int x){
	data = x;
	rank = 1;
}

int Leftist_node::rank() {
	return rank;
}

Leftist_node* Leftist_node::get_right_child() {
	return right_child;
}

Leftist_node* Leftist_node::get_left_child() {
	return left_child;
}



bool Leftist_node::is_empty(){
	return data == -1;
}

Leftist_node* Leftist_node::set_left_child(Leftist_node* t){
	

}

Leftist_node* Leftist_node::set_right_child(Leftist_node* t){


}

int Leftist_node::get_data(){


}

void Leftist_node::set_data(int x){


}
