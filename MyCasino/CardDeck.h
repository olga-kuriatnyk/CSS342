#pragma once
#include "Card.h"
const int kCardsInDeck = 52;

class CardDeck
{

public:
	CardDeck();

	void Shuffle();
	bool Cut(int num_cards);
	int CardsRemaing() const;
	Card Deal();
	bool ReturnCard(const Card& the_card);
	bool Contains(const Card& the_card) const; // cost because no change 
	bool RemoveCard(const Card& the_card);


private:
	Card deck[kCardsInDeck];
};

