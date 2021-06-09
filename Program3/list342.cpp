//  Olga Kuraitnyk
//  CSS342A
//  11/15/2020
//  Program 3: Linked List
//	The implementation for List342 Class.
//	Class for a templatized fully ordered singly linked list.

/*
#ifndef LIST342_CPP_
#define LIST342_CPP_

#include "list342.h" 
#include <fstream>
#include <string>

//	List342 class default constructor
template<class T>
List342<T>::List342()
{
	head_ = nullptr;
}

//	List342 class override constructor
template<class T>
List342<T>::List342(const List342& rhs)
{
	head_ = nullptr;
	*this = rhs;
}

//	List342 Destructor
template<class T>
List342<T>::~List342()
{
	T* answer = new T;
	while (Pop(answer));
}

// open the file, read the objects from file, and build an ordered linked list
template<class T>
bool List342<T>::BuidList(string fileName)
{
	ifstream in_file;
	in_file.open(fileName);

	if (in_file.is_open())
	{
		while (!in_file.eof())
		{
			T* item = new T;
			in_file >> *item;
			Insert(item); // insert each item into the list after reading them 
		}
		in_file.close();
	}
	else
	{
		cout << "File: " << fileName << "not found" << endl;
	}

	return true;
}

// insert an object in the list in the correct place 
// find correct place, create new node, priviuse node pointer should point in new node
// and new node point into the next nod, and new node has a pointer to a copy of an object 
template<class T>
bool List342<T>::Insert(T* obj)
{
	T* obj_copy = new T(*obj);

	if (head_ == nullptr) 	// empty list
	{
		head_ = new Node<T>;
		head_->data = obj_copy;
		head_->next = nullptr;
		return true;
	}

	if (*head_->data == *obj_copy) // duplicates are not allowed 
	{
		delete obj_copy;
		return false;
	}

	if (*head_->data > *obj_copy) // first item in line
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = obj_copy;
		new_node->next = head_;
		head_ = new_node;
		return true;
	}

	// find the right place to insert
	Node<T>* node_ptr = head_;
	while ((node_ptr->next != nullptr) && (*node_ptr->next->data < *obj_copy))
	{
		node_ptr = node_ptr->next;
	}

	if ((node_ptr->next != nullptr) && (*node_ptr->next->data == *obj_copy)) // duplicates are not allowed 
	{
		delete obj_copy;
		return false;
	}

	Node<T>* new_node = new Node<T>;
	new_node->data = obj_copy;
	new_node->next = node_ptr->next;
	node_ptr->next = new_node;
	return true;
}

// Remove the target item from the list
// Return the item using a second parameter that is passed in by reference
// If the item was found and removed return true, else return false
template<class T>
bool List342<T>::Remove(T target, T& result)
{
	if (head_ == nullptr) // list is empty
	{
		return false;
	}
	if (*head_->data == target) // removing the 1st element
	{
		Node<T>* temp = head_;
		result = *head_->data;
		head_ = head_->next;
		delete temp->data;
		delete temp;
		return true;
	}
	Node<T>* node_ptr = head_;

	while ((node_ptr->next != nullptr) && (*node_ptr->next->data != target))
	{
		node_ptr = node_ptr->next;
	}
	if (node_ptr->next == nullptr)
	{
		return false;
	}
	if (*node_ptr->next->data == target)
	{
		Node<T>* temp = node_ptr->next;
		result = *node_ptr->next->data;
		node_ptr->next = node_ptr->next->next;
		delete temp->data;
		delete temp;
		return true;
	}

	return false;
}

// If the item was found return true, else return false
// Return the item using a second parameter that is passed in by reference
template<class T>
bool List342<T>::Peek(T target, T& result) const
{
	if (head_ == nullptr) // list is empty
	{
		return false;
	}
	if (*head_->data == target) // the 1st element
	{
		result = *head_->data;
		return true;
	}
	if (*head_->data > target)
	{
		return false;
	}
	Node<T>* node_ptr = head_;
	while ((node_ptr->next != nullptr) && (*node_ptr->data != target))
	{
		node_ptr = node_ptr->next;
	}

	if (*node_ptr->data == target)	
	{
		result = *node_ptr->data;
		return true;
	}

	return false;
}

template<class T>
bool List342<T>::isEmpty() const
{
	if (head_ == nullptr)
	{
		return true;
	}
	return false;
}

//remove all items. deallocate all memory
template<class T>
void List342<T>::DeleteList()
{
	while (head_ != nullptr)
	{
		Node<T>* temp = head_; 
		head_ = head_->next;
		delete temp->data;
		delete temp;
	}
}

template<class T>
bool List342<T>::Pop(T* value)
{
	if (head_ == nullptr) // list is empty
	{
		return false;
	}

	Node<T>* temp = head_;
	value = temp->data;
	head_ =	head_->next;
	delete temp;
	return true;
}

// list that calling and list that past-in should be sorted 
// list past-in should be empty after termination 
// no duplicates 
template<class T>
bool List342<T>::Merge(List342<T>& list1)
{
	if (head_ == nullptr) // if calling list is empty
	{
		*this = list1;
		list1.head_ = nullptr;
		return true;
	}

	if (*this == list1) // if the list calls its self 
	{
		return true;
	}

	if (*head_->data > *list1.head_->data) // insert as a 1st element 
	{
		Node<T>* temp = list1.head_;
		list1.head_ = list1.head_->next;
		temp->next = head_;
		head_ = temp;
	}

	Node<T>* lhs_ptr = head_;
	Node<T>* rhs_ptr = list1.head_;

	while ((rhs_ptr != nullptr) && (lhs_ptr != nullptr))
	{
		if (*lhs_ptr->data == *rhs_ptr->data) // duplicates are not allowed 
		{
			Node<T>* temp = rhs_ptr;
			rhs_ptr = rhs_ptr->next;
			delete temp->data;
			delete temp;
			continue;
		}

		if ((lhs_ptr->next == nullptr) || ((*lhs_ptr->data < *rhs_ptr->data) && (*lhs_ptr->next->data > *rhs_ptr->data)))
		{
			Node<T>* temp = rhs_ptr; // pull out one element
			rhs_ptr = rhs_ptr->next; // move pnt for rhs
			temp->next = lhs_ptr->next; // insert temp into lhs
			lhs_ptr->next = temp;
			continue;
		}

		lhs_ptr = lhs_ptr->next;
	}

	list1.head_ = nullptr;

	return true;
}

// lists that are added remain unchanged 
template<class T>
List342<T> List342<T>::operator+(const List342<T>& rhs) const
{
	List342<T> list1_copy = *this;
	List342<T> list2_copy = rhs;
	List342<T> main;

	list1_copy += list2_copy;
	main = list1_copy;

	return main;
}

// list that is added remains unchenged 
template<class T>
List342<T> List342<T>::operator+=(List342<T>& rhs)
{
	if (this->head_ == rhs.head_) // if the list calls its self 
	{
		return *this;
	}

	if (rhs.head_ == nullptr)
	{
		return *this;
	}

	Node<T>* rhs_ptr = rhs.head_;
	while (rhs_ptr != nullptr)
	{
		this->Insert(rhs_ptr->data);
		rhs_ptr = rhs_ptr->next;
	}

	return *this;
}


template<class T>
List342<T>& List342<T>::operator=(const List342<T>& rhs)
{
	//make sure that not assignment to myself
	if (this == &rhs)
	{
		return *this;
	}

	if (rhs.head_ == nullptr)
	{
		this->DeleteList();
		return *this;
	}

	// Delete dynamic memory from *this
	this->DeleteList();

	//Deep copy 
	Node<T>* s_node = nullptr;
	Node<T>* d_node = nullptr;
	d_node = new Node<T>;
	d_node->data = (rhs.head_)->data;
	s_node = (rhs.head_)->next;
	this->head_ = d_node;

	while (s_node != nullptr)
	{
		d_node->next = new Node<T>;
		d_node = d_node->next;
		d_node->data = s_node->data;
		s_node = s_node->next;
	}

	return *this;
}

template<class T>
bool List342<T>::operator==(const List342<T>& rhs) const
{
	Node<T>* head_lhs = head_;
	Node<T>* head_rhs = rhs.head_;

	// itterate untile data is not equal or one of the list reach its the end
	while ((head_lhs->data == head_rhs->data) && (head_lhs->next != nullptr) && (head_rhs->next != nullptr))
	{
		head_lhs = head_lhs->next;
		head_rhs = head_rhs->next;
	}

	if (head_lhs->data != head_rhs->data) // found elements that are not equal return false
	{
		return false;
	}

	if ((head_lhs->next == nullptr) && (head_rhs->next == nullptr)) // reach the end. all elements were equal. return true
	{
		return true;
	}

	return false;
}

template<class T>
bool List342<T>::operator!=(const List342<T>& rhs) const
{
	return !(*this == rhs);
}

template<class T>
ostream& operator<<(ostream& out_stream, const List342<T>& rhs)
{
	if (rhs.isEmpty())
	{
		out_stream << "The list is empty.";
	}

	Node<T>* node_ptr = rhs.head_;

	while (node_ptr != nullptr)
	{
		out_stream << *node_ptr->data; 
		node_ptr = node_ptr->next;
	}

	return out_stream;
}

#endif
*/