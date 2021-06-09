//  Olga Kuraitnyk
//  CSS342A
//  11/15/2020
//  Program 3: Linked List
//	The implementation of Node class that  contains pointer to the next Node and a pointer to the data.

#include "node.h"

#ifndef NODE_CPP_
#define NODE_CPP_

//	Point class default constructor
template <class T>
inline Node<T>::Node()
{
	data = 0;
	next = nullptr;
}

#endif
