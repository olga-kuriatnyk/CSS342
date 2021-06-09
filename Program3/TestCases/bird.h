#ifndef BIRD_H_
#define BIRD_H_
#include <iostream>
#include <string>
using namespace std;

class Bird
{

friend ostream& operator<<(ostream &, const Bird &);
friend istream& operator>>(istream &, Bird &);

public:
	Bird();
	Bird(string name);
	Bird(string name, int id);

	string getType() const;
	int getID() const;
	void setID(const int &);
	void setType(const string &);

	bool operator<(const Bird &) const;
	bool operator<=(const Bird &) const ;
	bool operator>=(const Bird &) const;
	bool operator>(const Bird &) const;
	bool operator==(const Bird &) const;
	bool operator!=(const Bird &) const;

	~Bird();

private:
	string name;
	int id;
};
#endif

