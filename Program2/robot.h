//	Olga Kuraitnyk
//	CSS342A
//  11/02/2020
//	Problem 2: “The Greedy Robot”
//	The interface for Robot class that recursively finds the shortest distance
//	between robot location and treasure location.


#pragma once
#include "point.h"
#include <iostream>
#include <vector>
using namespace std;

class Robot
{
	// operators overload
	friend ostream& operator<<(ostream& outStream, const Robot& rbt);
	friend istream& operator>>(istream& inStream, Robot& rbt);

public:
	//Constructors
	Robot();
	Robot(Point robot, Point treasure, int max_step);

	//actions-verbs
	void FindPaths();
	bool operator==(const Robot& rbt) const;


private:
	Point robot_location_;
	Point treasure_location_;
	int max_step_;
	int num_of_paths_ = 0;

	vector<string> FindPathRecursive(Point robot, Point treasure, string cur_path);
};

