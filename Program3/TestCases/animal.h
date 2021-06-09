#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>
#include <iostream>
using namespace std;
class Animal
{


	friend ostream& operator<<(ostream &, const Animal &);
	friend istream& operator>>(istream &, Animal &);

public:
	Animal();
	~Animal();

	Animal(string name);
	Animal(string name, int id);

	string getType() const;
	int getID() const;
	void setType(const string &);
	void setID(const int &);

	bool operator<(const Animal &) const;
	bool operator<=(const Animal &) const;
	bool operator>=(const Animal &) const;
	bool operator>(const Animal &) const;
	bool operator==(const Animal &) const;
	bool operator!=(const Animal &) const;

private:
	string name;
	int id;
};
#endif

