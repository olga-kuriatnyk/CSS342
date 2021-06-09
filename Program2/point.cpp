//	Olga Kuraitnyk
//	CSS342A
//  11/02/2020
//	Problem 2: “The Greedy Robot”
//	The implementation for Point class that represents an integral point in a two-dimensional coordinate grid.


#include "point.h"

//	Point class default constructor
Point::Point()
{
	x_ = 0;
	y_ = 0;
}

//	Point class override constructor
Point::Point(int x, int y)
{
	this->x_ = x;
	this->y_ = y;
}

// Implementation of getters and setters
void Point::setValueX(int x)
{
	x_ = x; 
}

void Point::setValueY(int y)
{
	y_ = y;
}

int Point::getValueX() const
{
	return x_; 
}

int Point::getValueY() const
{
	return y_;
}

// Implementation of operators overload 
bool Point::operator==(const Point point) const
{
	return ((x_ == point.getValueX()) && (y_ == point.getValueY()));
}

istream& operator>>(istream& inStream, Point& rbt)
{
	inStream >> rbt.x_ >> rbt.y_;
	return inStream;
}
