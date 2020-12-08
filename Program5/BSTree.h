#ifndef BSTREE_H_
#define BSTREE_H_

#include "Account.h" 

class BSTree
{
public:
	BSTree();
//	BSTree(const BSTree& bst);
	~BSTree();

	bool Insert(Account* account_ptr);
	//bool Retrieve(int acct_number, Account* account_ptr);
	bool Retrieve(const int& account_id, Account*& account_ptr) const;

	//bool Remove(int acct_number);

	void Empty();

	int get_count();
	bool is_empty();

	BSTree operator=(const BSTree& bst);
	
private:
	struct Node 
	{
		Account* account_ptr_;
		Node* right_;
		Node* left_;
	};
	Node* root_;
};
#include "BSTree.h"
#endif

