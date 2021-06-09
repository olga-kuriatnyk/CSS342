//	Olga Kuraitnyk
//	CSS342A
//  11/02/2020
//	Problem 2: “The Greedy Robot”
//	The interface for Point class that represents an integral point in a two-dimensional coordinate grid. 


#pragma once
#include <iostream>
using namespace std;

class Point
{
	// operators overload
	friend istream& operator>>(istream& inStream, Point& rbt);

public:
	//Constructors
	Point();
	Point(int x, int y);

	//getters-setters
	void setValueX(int x);
	void setValueY(int y);
	int getValueX() const;
	int getValueY() const;

	//actions-verbs
	bool operator==(const Point point) const;

private:
	int x_;
	int y_;
};

