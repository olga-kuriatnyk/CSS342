#include "Card.h"

Card::Card()
{
	cout << "Card: Default Constructor " << endl;
	this->value = 1;	// initialize the data of our card
	this->suit = Spade;
}
Card::Card(int val, Suit the_suit)
{
	cout << "Card: int-suit Constructor " << endl;
	if ((val < 1) || (val > 13))
	{
		this->value = 1;
	}
	else
	{
		this->value = val;
	}
	this->suit = the_suit;
}

int Card::getValue() const
{
	return this->value;
}

Suit Card::getSuit() const
{
	return this->suit;
}

void Card::Print() const
{
	string card_suit;
	string card_value;
	card_suit = kSuits[this->getSuit()];

	switch (this->getValue())
	{
	case 1:
		card_value = "ace";
		break;
	case 11:
		card_value = "jack";
		break;
	case 12:
		card_value = "queen";
		break;
	case 13:
		card_value = "king";
		break;
	default:
		card_value = to_string(this->getValue());
	}
	cout << card_value << " of " << card_suit;
}

ostream& operator<<(ostream& out_stream, const Card& the_card)
{
	string card_suit;
	string card_value;
	card_suit = kSuits[the_card.getSuit()];

	switch (the_card.getValue())
	{
	case 1:
		card_value = "ace";
		break;
	case 11:
		card_value = "jack";
		break;
	case 12:
		card_value = "queen";
		break;
	case 13:
		card_value = "king";
		break;
	default:
		card_value = to_string(the_card.getValue());
	}
	out_stream << card_value << " of " << card_suit;
	return out_stream;
}
