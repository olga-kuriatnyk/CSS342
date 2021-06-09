/*
	Olga Kuraitnyk
	CSS342A
	10/16/2020
	Program 1: TimeSpan
	The main method for a TimeSpan class.
*/

#include <iostream>
#include "TimeSpan.h"

int main()
{
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);    
	TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;	

	cout << "dur1: " << dur1 << endl; // 77,39,6
	cout << "dur2: " << dur2 << endl; //  2,8 
	cout << "dur3: " << dur3 << endl; // 7,37
	cout << "dur4: " << dur4 << endl; // 0
	cout << "dur5: " << dur5 << endl; // -1,-46,-58
	cout << "dur6: " << dur6 << endl; // 7,37,0
	cout << "dur7: " << dur7 << endl; // 0
	dur7 = dur1 + dur3;
	cout << "dur7 = dur1 + dur3: " << dur7 << endl; // 85,16,6
	dur7 -= dur3;
	cout << "dur7 -= dur3: " << dur7 << "\n" << endl; // 77,39,6

	cout << "dur2: " << dur2 << endl; //  2,8 
	cout << "dur6: " << dur6 << endl; // 7,37,0
	if (dur2 != dur6)
	{
		cout << "Durations are different\n" << endl;
	}
	else
	{
		cout << "Durations are the same\n" << endl;
	}
	
	cout << "dur6: " << dur6 << endl;
	cout <<  "dur8: " << dur8 << endl;
	
	if (dur8 == dur6)
	{
		cout << "The dur you entered is equal to dur6" << endl;
	}
	else
	{
		cout << "The dur you entered is not equal to dur6" << endl;
	}
}


