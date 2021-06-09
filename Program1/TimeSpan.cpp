/*
	Olga Kuraitnyk
	CSS342A
	10/16/2020
	Program 1: TimeSpan
	The implementaion for a TimeSpan class which represents a duration of time in hours, minutes, and seconds.
*/

#include "TimeSpan.h"
#include <cmath>

TimeSpan::TimeSpan()
{
	seconds_ = 0;
	minutes_ = 0;
	hours_ = 0;
}
TimeSpan::TimeSpan(double seconds)
{
	seconds_ = round(seconds);
	simplify();
}
TimeSpan::TimeSpan(double minutes, double seconds)
{
	seconds_ = round(seconds);
	minutes_ = minutes;
	simplify();
}
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	seconds_ = round(seconds);
	minutes_ = minutes; 
	hours_ = hours;
	simplify();
}

double TimeSpan::getHours() const
{
	return hours_;
}

double TimeSpan::getMinutes() const
{
	return minutes_;
}

double TimeSpan::getSeconds() const
{
	return seconds_;
}

bool TimeSpan::setTime(double hours, double minutes, double seconds)
{
	hours_ = hours;
	minutes_ = minutes;
	seconds_ = seconds;
	return true;
}

void TimeSpan::simplify()
{
	if (hours_ != 0)
	{
		seconds_ +=  ((hours_ * 60) + minutes_) * 60;
		minutes_ = 0, hours_ = 0;
		seconds_ = int(seconds_); 
	}

	if ((seconds_ >= 60) || (seconds_ <= -60))
	{
		minutes_ = int(seconds_) / 60;
		seconds_ = int(seconds_) % 60;
		if ((minutes_ >= 60) || (minutes_ <= -60))
		{
			hours_ = int(minutes_) / 60;
			minutes_ = int(minutes_) % 60;
		}
	}
}

TimeSpan TimeSpan::operator+(const TimeSpan& dur) const
{
	TimeSpan result = *this;
	result += dur;
	return result;
}
TimeSpan TimeSpan::operator+=(const TimeSpan& dur)
{
	hours_ = hours_ + dur.hours_;
	minutes_ = minutes_ + dur.minutes_;
	seconds_ = seconds_ + dur.seconds_;
	simplify();
	return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan& dur) const
{
	TimeSpan result = *this;
	result -= dur;
	return result;
}
TimeSpan TimeSpan::operator-=(const TimeSpan& dur)
{
	hours_ = hours_ - dur.hours_;
	minutes_ = minutes_ - dur.minutes_;
	seconds_ = seconds_ - dur.seconds_;
	simplify();
	return *this;
}

bool TimeSpan::operator==(const TimeSpan& dur) const
{
	return((hours_ == dur.hours_) && (minutes_ == dur.minutes_) && (seconds_ == dur.seconds_));
}
bool TimeSpan::operator!=(const TimeSpan& dur) const
{
	return ((hours_ != dur.hours_) || (minutes_ != dur.minutes_) || (seconds_ != dur.seconds_));
}

ostream& operator<<(ostream& outStream, const TimeSpan& dur)
{
	if ((dur.hours_ == 0) && (dur.minutes_ == 0))
	{
		outStream << "Seconds: " << dur.seconds_;
	}
	else if (dur.hours_ == 0)
	{
		outStream << "Minutes: " << dur.minutes_ << ", Seconds: " << dur.seconds_;
	}
	else
	{
		outStream << "Hours: " << dur.hours_ << ", Minutes: " << dur.minutes_ << ", Seconds: " << dur.seconds_;
	}
	return outStream;
}

istream& operator>>(istream& inStream, TimeSpan& dur)
{
	inStream >> dur.hours_ >> dur.minutes_ >> dur.seconds_;
	return inStream;
}