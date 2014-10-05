#include <iostream>
#include "Binary_search_tree.cpp"

int main(int argc, char* argv[]) {
	Binary_search_tree* BST = new Binary_search_tree();
	BST->insert(5);
	BST->inorder();
	BST->insert(3);
	BST->inorder();
	BST->insert(4);
	BST->inorder();
	BST->insert(6);
	BST->inorder();
	BST->remove(3);
	BST->inorder();
}