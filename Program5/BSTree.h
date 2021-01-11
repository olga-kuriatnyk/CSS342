//  Olga Kuraitnyk
//  CSS342A
//  12/10/2020
//  Program 5: The Jolly Banker
//  BSTree.h
//  Interface for BSTree Class. 
//  Node contains pointer to the right Node, left Node and a pointer to the Account.
//  This class includes two private Recursive functions for storing data in the binary search tree and printing data.  

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Account.h" 

class BSTree
{


public:
	//	Constructor-Destructor
	BSTree();
	BSTree(const BSTree& rhs);
	~BSTree();

	//	Actions-verbs
	bool Insert(Account* account_ptr);
	bool Retrieve(const int& account_id, Account*& account_ptr) const;
	void Display() const;
	void Empty();
	bool is_empty() const;

	BSTree& operator=(const BSTree& rhs);
	
private:
	struct Node
	{
		Account* account_ptr_;
		Node* right_;
		Node* left_;
	};
	Node* root_;

	void preOrderRetrive(Node* current);

	bool RecursiveInsert(Node* current, Account* insert);
	void RecursivePrint(Node* current) const;

};
#include "BSTree.h"
#endif

