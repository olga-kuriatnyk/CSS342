#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Suit { Heart, Diamond, Club, Spade };
const string kSuits[4] = { "heart", "diamond", "club", "spade" };

class Card
{
friend ostream& operator<<(ostream& out_stream, const Card& the_card);
public:
	Card(); 
	Card(int val, Suit the_suit); // constructor

	int getValue() const;
	Suit getSuit() const;

	void Print() const;

private:
	int value;
	Suit suit;
};

