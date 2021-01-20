//	Interface for List342 Class for a templatized fully ordered singly linked list.

#ifndef LIST342_H_
#define LIST342_H_

#include <iostream>
using namespace std;

#include <ostream>
#include "node.h"

template <class T>
class List342
{
    //	Operator overload
    template <class T>
    friend ostream &operator<<(ostream &out_stream, const List342<T> &rhs);

public:
    //	Constructors
    List342();
    //	Copy constructor
    List342(const List342 &rhs);

    //	Destructor
    ~List342();

    //	Actions-verbs
    bool BuidList(string fileName);
    bool Insert(T *obj);
    bool Remove(T target, T &result);
    bool Peek(T target, T &result) const;
    bool isEmpty() const;
    void DeleteList();
    bool Merge(List342<T> &list1);

    //	Operators overload
    List342<T> operator+(const List342<T> &rhs) const;
    List342<T> operator+=(List342<T> &rhs);

    List342<T> &operator=(const List342<T> &rhs);

    bool operator==(const List342<T> &rhs) const;
    bool operator!=(const List342<T> &rhs) const;

private:
    Node<T> *head_;
    bool Pop(T *value);
};
#include "list342.cpp"
#endif