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
	bool is_empty() const;

	// DO I NEED THIS? 
	//int get_count() const;
	//BSTree operator=(const BSTree& bst);
	
private:
	struct Node 
	{
		Account* account_ptr_;
		Node* right_;
		Node* left_;
	};
	Node* root_;

	bool RecursiveInsert(Node* current, Account* insert);

};
#include "BSTree.h"
#endif

