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
	if (insert_account_id < 1000 || insert_account_id > 9999)
	{
		cout << "ERROR: Account Number Not Valid" << endl;
		return false;
	}

	if (root_ == NULL)
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
		// TODO: implement Recursive Insert ? 

	}
	return false;
}

//bool BSTree::Retrieve(const int& account_id, Account*& account_ptr) const
//{
//	Node* current = root_;
//	bool search = false;
//
//	while (!search)
//	{
//		if ((current != NULL) && (account_id == current->account_ptr_->getAccountID())) //found the account_id 
//		{
//			search = true;
//			account_ptr = current->account_ptr_;
//			return search;
//		}
//		else if ((current != NULL) && (account_id > current->account_ptr_->getAccountID()))
//		{
//			current = current->right_;
//		}
//		else if ((current != NULL) && (account_id < current->account_ptr_->getAccountID()))
//		{
//			current = current->left_;
//		}
//		//else
//		//{
//		//	search = true;
//		//}
//	}
//
//	cout << "ERROR: Account Number " << account_id << " not found." << endl;
//	return search;
//}

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

	cout << "ERROR: Account Number " << account_id << " not found." << endl;
	return false;
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

bool BSTree::RecursiveInsert(Node* current, Account* insert)
{
	if (insert->getAccountID() > current->account_ptr_->getAccountID())
	{
		if (current->right_ == NULL) // found the place
		{

		}
		else
		{

		}
	}

	else if (insert->getAccountID() < current->account_ptr_->getAccountID())
	{
		if (current->left_ == NULL) // found the place
		{

		}
		else
		{

		}
	}

	else // insert->getAccountID() == current->account_ptr_->getAccountID()
	{
		cout << "ERROR: Account " << insert->getAccountID() << " is already open. Transaction refused." << endl;
	}

	return false;
}

#endif