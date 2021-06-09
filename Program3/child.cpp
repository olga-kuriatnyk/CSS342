//  Olga Kuraitnyk
//  CSS342A
//  11/15/2020
//  Program 3: Linked List
//	The implementation for Child Class. 
//	The child class contains a first name (string), last name (string), and age (int).

#include "child.h"

//	Point class default constructor
Child::Child()
{
	first_name_ = "";
	last_name_ = "";
	age_ = 0;
}

//	Point class override constructor
Child::Child(string first_name, string last_name, int age)
{
	first_name_ = first_name;
	last_name_ = last_name;
	age_ = age;
}

// if the last name, first name and age equal return true
bool Child::operator==(const Child& child) const
{
	if (last_name_ != child.last_name_)
	{
		return false;
	}
	if (first_name_ != child.first_name_)
	{
		return false;
	}
	if (age_ != child.age_)
	{
		return false;
	}

	return true;
}

bool Child::operator!=(const Child& child) const
{
	return !(*this == child);
}

//compares names alphabetically by last name first; first name second;and then age.
bool Child::operator>(const Child& child) const
{
	if (last_name_ > child.last_name_) 
	{
		return true;
	}
	if ((last_name_ == child.last_name_) && (first_name_ > child.first_name_))
	{
		return true;
	}
	if ((last_name_ == child.last_name_) && (first_name_ == child.first_name_) && (age_ > child.age_))
	{
		return true;
	}
	return false;
}
bool Child::operator<(const Child& child) const
{
	if (*this == child)
	{
		return false;
	}
	return !(*this > child);
}

istream& operator>>(istream& in_stream, Child& child)
{
	in_stream >> child.first_name_ >> child.last_name_ >> child.age_;
	return in_stream;
}

ostream& operator<<(ostream& out_stream, const Child& child)
{
	out_stream << child.first_name_ << child.last_name_ << child.age_ ;
	return out_stream;
}
