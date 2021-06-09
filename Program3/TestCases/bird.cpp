#include "pch.h"
#include "Bird.h"

Bird::Bird()
{
	id = 0;
}

Bird::Bird(string n)
{
	name = n;
	id = 0;
}

Bird::Bird(string n, int i)
{
	name = n;
	id = i;
}

string Bird::getType() const
{
	return name;
}

int Bird::getID() const
{
	return id;
}


void Bird::setID(const int &i)
{
	id = i;
}
void Bird::setType(const string &n)
{
	name = n;
}

bool Bird::operator<(const Bird &rBird) const
{
	return (this->id < rBird.id);
}

bool Bird::operator<=(const Bird &rBird) const
{
	return (this->id <= rBird.id);
}

bool Bird::operator>(const Bird &rBird) const
{
	return (this->id > rBird.id);
}

bool Bird::operator>=(const Bird &rBird) const
{
	return (this->id >= rBird.id);
}

bool Bird::operator==(const Bird &rBird) const
{
	return (this->id == rBird.id);
}

bool Bird::operator!=(const Bird &rBird) const
{
	return (this->id != rBird.id);
}

ostream& operator<<(ostream &outStream, const Bird &b)
{
	outStream << b.name << b.id;
	return outStream;
}

istream& operator>>(istream &inStream, Bird &b)
{
	inStream >> b.name;
	inStream >> b.id;
	return inStream;
}


Bird::~Bird()
{
}
