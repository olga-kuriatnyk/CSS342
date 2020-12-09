#ifndef BSTREE_CPP_
#define BSRTREE_CPP_

#include "BSTree.h"

BSTree::BSTree()
{
	root_ = NULL;
}

BSTree::~BSTree()
{
	Empty();
}

bool BSTree::Insert(Account* account_ptr)
{
	int insert_account_id = account_ptr->getAccountID();
	if (insert_account_id < 1000 || insert_account_id > 9999) // account_id is not valid
	{
		cout << "ERROR: Account Number Not Valid" << endl;
		return false;
	}

	if (root_ == NULL) // when tree is empty 
	{
		root_ = new Node;
		root_->account_ptr_ = account_ptr;
		root_->left_ = NULL;
		root_->right_ = NULL;
		return true;
	}

	else
	{
		Node* current = root_;
		RecursiveInsert(current, account_ptr); // finds the right plane for the Node

	}
	return false;
}

bool BSTree::Retrieve(const int& account_id, Account*& account_ptr) const
{
	Node* current = root_;

	while (current != NULL)
	{
		if (account_id == current->account_ptr_->getAccountID())
		{
			account_ptr = current->account_ptr_;
			return true;
		}

		else if (account_id > current->account_ptr_->getAccountID())
		{
			current = current->right_;
		}

		else if (account_id < current->account_ptr_->getAccountID())
		{
			current = current->left_;
		}
	}

	return false;
}

void BSTree::Display() const
{
	if (root_ == NULL)
	{
		cout << "ERROR: ACCOUNT LIST IS EMPTY" << endl;
		return;
	}
	RecursivePrint(root_);
}

void BSTree::Empty() // TODO: test
{
	delete root_;
	root_ = NULL;
}

bool BSTree::is_empty() const
{
	if (root_->left_ == NULL && root_->right_ == NULL)
	{
		return true;
	}
	return false;
}

// RecursiveInsert() is a recursive function that finds the right plane for the Node in the tree
// if the account_is already opent print the Error message 
bool BSTree::RecursiveInsert(Node* current, Account* insert)
{
	if (insert->getAccountID() > current->account_ptr_->getAccountID())
	{
		if (current->right_ == NULL) // found the place
		{
			Node* insert_in_tree = new Node();
			insert_in_tree->account_ptr_ = insert;
			insert_in_tree->left_ = NULL;
			insert_in_tree->right_ = NULL;
			current->right_ = insert_in_tree;
			return true;
		}
		else
		{
			return RecursiveInsert(current->right_, insert);
		}
	}

	else if (insert->getAccountID() < current->account_ptr_->getAccountID())
	{
		if (current->left_ == NULL) // found the place
		{
			Node* insert_in_tree = new Node();
			insert_in_tree->account_ptr_ = insert;
			insert_in_tree->left_ = NULL;
			insert_in_tree->right_ = NULL;
			current->left_ = insert_in_tree;
			return true;
		}
		else
		{
			return RecursiveInsert(current->left_, insert);
		}
	}

	else // insert->getAccountID() == current->account_ptr_->getAccountID()
	{
		cout << "ERROR: Account " << insert->getAccountID() << " is already open. Transaction refused." << endl;
	}

	return false;
}

void BSTree::RecursivePrint(Node* current) const
{
	if ((current->right_ != NULL) && (current->left_ != NULL))
	{
		RecursivePrint(current->right_);
		cout << *(current->account_ptr_) << endl; // TODO: do I need this?
		RecursivePrint(current->left_);
	}

	else if (current->left_ != NULL)
	{
		cout << *(current->account_ptr_) << endl;
		RecursivePrint(current->left_);
	}

	else if (current->right_ != NULL)
	{
		cout << *(current->account_ptr_) << endl;
		RecursivePrint(current->right_);
	}

	else
	{
		cout << *(current->account_ptr_) << endl;
	}
}



#endif