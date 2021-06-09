//	Olga Kuraitnyk
//	CSS342A
//  11/02/2020
//	Problem 2: “The Greedy Robot”
//	The implementation for Robot class that recursively finds the shortest distance
//	between robot location and treasure location.


#include "robot.h"
#include <vector> 

// constanc characters for each derection 
const char NORTH = 'N';
const char SOUTH = 'S';
const char WEST = 'W';
const char EAST = 'E';

void AppendToVector(vector<string>& results, vector<string>& result);
bool IsAllowedToMove(string& cur_path, char direction, int& max_step_);
void PrintPathsInfo(vector<string> paths);

//	Robot class default constructor
Robot::Robot()
{
	robot_location_;
	treasure_location_;
	max_step_ = 0;
}

//	Robot class override constructor
Robot::Robot(Point robot_location, Point treasure_location, int max_step)
{
	this->robot_location_ = robot_location;
	this->treasure_location_ = treasure_location;
	this->max_step_ = max_step;
}

//	Validates input, if robot location and treasure location are equal returns message -> no paths 
//	else calls recursive method to find all paths, then calls the method to print paths and it's number
void Robot::FindPaths()
{
	if (this->robot_location_ == this->treasure_location_)
	{
		cout << "You entered the same point for robot and treasure." << endl;
	}
	else
	{
		vector<string> paths = FindPathRecursive(this->robot_location_, this->treasure_location_, "");
		PrintPathsInfo(paths);
	}
}

//	FindPathRecursive() is a recursive function that finds all shortest distance between robot location
//	and treasure location, and stores them in a vector.
//	It call AppendToVector when finds a unique path to add it to the vector of all paths 
vector<string> Robot::FindPathRecursive(Point robot_location, Point treasure_location, string cur_path)
{
	vector<string> found_paths;

	// when found the treasure returns the path
	if (robot_location == treasure_location)
	{
		vector<string> path;
		path.push_back(cur_path);
		return path;
	}

	// if allowed to go North (cheking the max step) and need to go North (robot Y coordinate < treasure Y coordinate)
	// Creates new point for the nest location for robot and calls FindPathRecursive() and add new character to current path
	// then adds new path to the found paths
	if (IsAllowedToMove(cur_path, NORTH, max_step_) && (robot_location.getValueY() < treasure_location.getValueY()))
	{
		Point next_step_robot(robot_location.getValueX(), robot_location.getValueY() + 1);
		vector<string> partial_path = FindPathRecursive(next_step_robot, treasure_location, cur_path + NORTH);
		AppendToVector(found_paths, partial_path);
	}

	//if allowed to go South (cheking the max step) and need to go South (robot Y coordinate > treasure Y coordinate)
	if (IsAllowedToMove(cur_path, SOUTH, max_step_) && (robot_location.getValueY() > treasure_location.getValueY()))
	{
		Point next_step_robot(robot_location.getValueX(), robot_location.getValueY() - 1);
		vector<string> partial_path = FindPathRecursive(next_step_robot, treasure_location, cur_path + SOUTH);
		AppendToVector(found_paths, partial_path);
	}

	//if allowed to go East (cheking the max step) and need to go East (robot X coordinate < treasure X coordinate)
	if (IsAllowedToMove(cur_path, EAST, max_step_) && (robot_location.getValueX() < treasure_location.getValueX()))
	{
		Point next_step_robot(robot_location.getValueX() + 1, robot_location.getValueY());
		vector<string> partial_path = FindPathRecursive(next_step_robot, treasure_location, cur_path + EAST);
		AppendToVector(found_paths, partial_path);
	}

	//if allowed to go Weast (cheking the max step) and need to go Weast (robot X coordinate > treasure X coordinate)
	if (IsAllowedToMove(cur_path, WEST, max_step_) && (robot_location.getValueX() > treasure_location.getValueX()))
	{
		Point next_step_robot(robot_location.getValueX() - 1, robot_location.getValueY());
		vector<string> partial_path = FindPathRecursive(next_step_robot, treasure_location, cur_path + WEST);
		AppendToVector(found_paths, partial_path);
	}

	return found_paths;
}

// Adds two vectors together 
void AppendToVector(vector<string>& vector1, vector<string>& vector2)
{
	for (int i = 0; i < vector2.size(); i++)
	{
		vector1.push_back(vector2[i]);
	}
}

// IsAllowedToMove() function checks if the robot is allowed to go in the chose direction 
// checks the past characters in path, so robot cannot move in the same direction more than max step
bool IsAllowedToMove(string& cur_path, char direction, int& max_step_)
{
	int index = 0;
	int path_size = cur_path.size();

	if (max_step_ > path_size)
	{
		return true;
	}

	while (index < max_step_)
	{
		if (cur_path[path_size - 1 - index] == direction)
		{
			index++;
		}
		else
		{
			return true;
		}
	}
	return false;
}
// prints all paths and the number of paths
void PrintPathsInfo(vector<string> paths)
{
	int num_of_paths = paths.size();
	if (num_of_paths == 0)
	{
		cout << "No shortest possible paths were found." << endl;
	}
	else
	{
		for (int i = 0; i < paths.size(); i++)
		{
			cout << paths[i] << "\n";
		}
		cout << "Number of paths: " << num_of_paths << endl;
	}
}

ostream& operator<<(ostream& outStream, const Robot& rbt)
{
	return outStream;
}

istream& operator>>(istream& inStream, Robot& rbt)
{
	inStream >> rbt.robot_location_ >> rbt.treasure_location_ >> rbt.max_step_;
	return inStream;
}

bool Robot::operator==(const Robot& rbt) const
{
	return (rbt.robot_location_ == rbt.treasure_location_);
}


