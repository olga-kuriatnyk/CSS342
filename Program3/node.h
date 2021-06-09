//  Olga Kuraitnyk
//  CSS342A
//  11/15/2020
//  Program 3: Linked List
//	Interface for Node Class. Node contains pointer to the next Node and a pointer to the data.

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

template<class T>
class Node
{
public: 
	//	Constructor
	Node();

	T* data;
	Node* next;

};
#include "node.cpp"
#endif


