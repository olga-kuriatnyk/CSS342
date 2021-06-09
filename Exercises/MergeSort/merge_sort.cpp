// merge_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "sort_impls.h"
using namespace std;

const int kNumValues = 50;

int main()
{

	vector<int> v;

	for (int i = 0; i < kNumValues; i++)
	{
		v.push_back(rand());
	}

	for (int i = 0; i < kNumValues; i++)
	{
		cout << v[i] << " ";
	}

	MergeSort(v, 0, v.size() - 1);
	cout << endl << endl;

	for (int i = 0; i < kNumValues; i++)
	{
		cout << v[i] << " ";
	}
}
