//  Olga Kuraitnyk
//  CSS342A
//  11/15/2020
//  Program 3: Linked List
//	Interface for Child Class.
//	The child class contains a first name (string), last name (string), and age (int).

#pragma once

#include <string>
#include <iostream>
using namespace std;

class Child
{
	//	Operators overload
	friend istream &operator>>(istream &in_stream, Child &child);
	friend ostream &operator<<(ostream &out_stream, const Child &child);

public:
	//	Constructors
	Child();
	Child(string first_name, string last_name, int age);

	//	Operators overload
	bool operator==(const Child &child) const;
	bool operator!=(const Child &child) const;

	bool operator>(const Child &child) const;
	bool operator<(const Child &child) const;

private:
	string first_name_;
	string last_name_;
	int age_;
};