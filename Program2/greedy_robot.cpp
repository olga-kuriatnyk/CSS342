//  Olga Kuraitnyk
//  CSS342A
//  11/02/2020
//  Problem 2: “The Greedy Robot”
//  This file contains the 'main' function. Program execution begins and ends there.
//  Assumptions:  that user knows how to enter data correctly.
//  Error cheking only for negative numbers.


#include <iostream>
#include "robot.h"
#include "point.h"


int main(int argc, char* argv[])
{
    cout << "Welcom to Greedy Robot!" << endl;
    cout << "Please enter your command" << endl;
    int x, y, x2, y2, step;
    cin >> x >> y >> x2 >> y2 >> step;
    Point robot(x, y);
    Point treasure(x2, y2);
    Robot greedy_robot(robot, treasure, step) ;
    greedy_robot.FindPaths(); 
    cout << greedy_robot << "\n";
    
    return 0;
}
