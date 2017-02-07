
#ifndef UnoPlayer_h
#define UnoPlayer_h
#include"OrderedList.h"
#include"UnoCard.h"
#include<string>
#include<iostream>

using namespace std;

class UnoPlayer {
private:
	static unsigned playerNum;
	unsigned numCards;
	std::string _name;
	OrderedList <UnoCard> _hand;
public:
	UnoPlayer();
	~UnoPlayer();
	int cardMatch(UnoCard pile);
	void addCard(UnoCard card);
	void removeCard(int pos);
	UnoCard retrieveCard(int pos);
	unsigned getNumofCards();
	std::string getPlayerName();
	friend std::ostream& operator<<(std::ostream& os, UnoPlayer cards);
};



inline ostream& operator<<(ostream& os, UnoPlayer cards)
{
	os << cards._name << " Cards:\n\t";
	for (unsigned i = 0; i < cards._hand.getLength(); i++)
	{
		os << cards._hand.retrieve(i) << '\t';
	}
	os << '\n';
	return os;
}
#endif