#ifndef SORTED_LIST_H_
#define SORTED_LIST_H_

#include <vector>
#include <iostream>
using namespace std;

template<class T>
class SortedList
{
	public:
		void Add(const T& item);
		void Print() const;
		void Sort();

	private:
		vector<T> the_list_;
};
#include "sorted_list.cpp"
#endif
