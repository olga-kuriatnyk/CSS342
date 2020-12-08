#pragma once
#include "Account.h" 

class BSTree
{
public:
	BSTree();
//	BSTree(const BSTree& bst);
	~BSTree();

	bool Insert(Account* account_ptr);
	bool Retrieve(int acct_number, Account* account_ptr);
	//bool Remove(int acct_number);

	void Empty();

	int get_count();
	bool is_empty();

	BSTree operator=(const BSTree& bst);

private:
	struct Node 
	{
		Account* account_ptr;
		Node* right;
		Node* left;
	};
	Node* root_;
};

