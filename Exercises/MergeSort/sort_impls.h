#ifndef SORT_IMPLS_H
#define SORT_IMPLS_H_
#include <vector>
using namespace std;


void Merge(vector<int>& item_vector, int first, int mid, int last)
{
	int* temp_arr;
	int size = last - first + 1;
	temp_arr = new int[size];

	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;
	int index = 0;

	while ((first1 <= last1) && (first2 <= last2)) 
	{
		if (item_vector[first1] < item_vector[first2])
		{ 
			temp_arr[index] = item_vector[first1];
			first1++; 
		} 
		else 
		{ 
			temp_arr[index] = item_vector[first2];
			first2++; 
		}    
		index++; 
	}
	while (first1 <= last1) 
	{ 
		temp_arr[index] = item_vector[first1];
		first1++;   
		index++; 
	}
	while (first2 <= last2) 
	{ 
		temp_arr[index] = item_vector[first2];
		first2++;
		index++;
	}
	for (index = 0; index < size; index++) 
	{ 
		item_vector[first] = temp_arr[index];
		first++; 
	}

	delete[] temp_arr;
}

void MergeSort(vector<int>& item_vector, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(item_vector, first, mid);
		MergeSort(item_vector, mid, last);
		Merge(item_vector, first, mid, last);
	}
}
#endif 
