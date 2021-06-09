#include "pch.h"
#include "Animal.h"


Animal::Animal()
{
	name = "";
	id = 0;
}

Animal::~Animal()
{
}

Animal::Animal(string name)
{
	this->name = name;
	id = 0;
}

Animal::Animal(string name, int id)
{
	this->name = name;
	this->id = id;
}

string Animal::getType() const
{
	return name;
}

int Animal::getID() const
{
	return id;
}

void Animal::setType(const string &name)
{
	this->name = name;
}

void Animal::setID(const int &id)
{
	this->id = id;
}

bool Animal::operator<(const Animal &rhs) const
{
	return (id < rhs.id);
}

bool Animal::operator<=(const Animal &rhs) const
{
	return (id <= rhs.id);
}

bool Animal::operator>=(const Animal &rhs) const
{
	return (id >= rhs.id);
}

bool Animal::operator>(const Animal &rhs) const
{
	return (id > rhs.id);
}

bool Animal::operator==(const Animal &rhs) const
{
	return (id == rhs.id);
}

bool Animal::operator!=(const Animal &rhs) const
{
	return (id != rhs.id);
}


ostream& operator<<(ostream &outStream, const Animal &an)
{
	outStream << an.name << an.id;
	return outStream;
}

istream& operator>>(istream &inStream, Animal &an)
{
	inStream >> an.name;
	inStream >> an.id;
	return inStream;
}

