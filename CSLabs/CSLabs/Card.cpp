
#include "Card.h"


Card::Card(Suit suit, Denomination denomination)
	: m_suit(suit)
	, m_denomination(denomination)
{
}

// destructor
Card::~Card()
{
}

char Card::toCharSuit()
{
	if (m_suit == HEARTS)   return 'H';
	else if (m_suit == CLUBS)    return 'C';
	else if (m_suit == SPADES)   return 'S';
	else                       return 'D';
}

char Card::toCharDenomination()
{
	if (m_denomination == N2)	return '2';
	else if (m_denomination == N3)	return '3';
	else if (m_denomination == N4)	return '4';
	else if (m_denomination == N5)	return '5';
	else if (m_denomination == N6)	return '6';
	else if (m_denomination == N7)	return '7';
	else if (m_denomination == N8)	return '8';
	else if (m_denomination == N9)	return '9';
	else if (m_denomination == N10)	return 't';
	else if (m_denomination == JACK)	return 'j';
	else if (m_denomination == QUEEN)	return 'q';
	else if (m_denomination == KING)	return 'k';
	else                            return 'a';
}
std::ostream& operator<<(std::ostream& os, const Card &c) {
	int suit = c.getSuit();
	int demo = c.getDenomination();
	switch (demo) {
	case 11:
		os << "Jack";
		break;
	case 12:
		os << "Queen";
		break;
	case 13:
		os << "King";
		break;
	case 14:
		os << "Ace";
		break;
	default:
		os << demo;
	}
	switch (suit) {
	case 1:
		os << " of Spades";
		break;
	case 2:
		os << " of Hearts";
		break;
	case 3:
		os << " of Clubs";
		break;
	default:
		os << " of Diamonds";
	}
	return os;
}