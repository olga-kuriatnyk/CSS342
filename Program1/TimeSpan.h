/*
	Olga Kuraitnyk
	CSS342A
	10/16/2020
	Program 1: TimeSpan
	The interface for a TimeSpan class which represents a duration of time in hours, minutes, and seconds.
*/
#pragma once
#include <iostream>
using namespace std;

class TimeSpan
{
	friend ostream& operator<<(ostream &outStream, const TimeSpan& dur);
	friend istream& operator>>(istream& inStream, TimeSpan& dur);

public:

	//Constructors
	TimeSpan();
	TimeSpan(double seconds);
	TimeSpan(double minutes, double seconds);
	TimeSpan(double hours, double minutes, double seconds);

	//getters-setters
	double getHours() const;
	double getMinutes() const;
	double getSeconds() const;

	bool setTime(double hours, double minutes, double seconds);

	//actions-verbs
	TimeSpan operator+(const TimeSpan& dur) const;
	TimeSpan operator+=(const TimeSpan& dur);

	TimeSpan operator-(const TimeSpan& dur) const;
	TimeSpan operator-=(const TimeSpan& dur);

	bool operator==(const TimeSpan &dur) const;
	bool operator!=(const TimeSpan& dur) const;

private:
	double seconds_ = 0;
	double minutes_ = 0;
	double hours_ = 0;
	void simplify();
};

