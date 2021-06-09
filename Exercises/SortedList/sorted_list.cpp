#ifndef SORTED_LIST_CPP_
#define SORTED_LIST_CPP_

#include "sorted_list.h"

template<class T> 
void SortedList<T>::Add(const T& item)
{
	the_list_.push_back(item);
}

template<class T>
void SortedList<T>::Print() const
{
	for (int i = 0; i < the_list_.size(); i++)
	{
		cout << the_list_[i] << endl;
	}
}

template<class T>
void SortedList<T>::Sort()
{
	for (int place = 1; place < the_list_.size(); place++)
	{
		T temp = the_list_[place];
		int i = place;
		while ((i > 0) && (the_list_[i - 1] > temp))
		{
			the_list_[i] = the_list_[i - 1];
			i--;
		}
		the_list_[i] = temp;
	}
}
#endif 