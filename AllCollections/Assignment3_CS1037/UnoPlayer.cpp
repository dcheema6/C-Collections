#include"UnoPlayer.h"

unsigned UnoPlayer::playerNum = 0;

UnoPlayer::UnoPlayer()
{
	_name = "Player";
	numCards = 0;
	playerNum++;
}

UnoPlayer::~UnoPlayer()
{
	_hand.~OrderedList();
}

int UnoPlayer::cardMatch(UnoCard pile)
{
	for (unsigned i = 1; i <= _hand.getLength(); i++)
	{
		if (_hand.retrieve(i) == pile)
		{
			return i;
		}
	}
	return 0;
}

void UnoPlayer::addCard(UnoCard card)
{
	_hand.insert(card);
	numCards++;
}

void UnoPlayer::removeCard(int pos)
{
	_hand.remove(pos);
	numCards--;
}

UnoCard UnoPlayer::retrieveCard(int pos)
{
	return _hand.retrieve(pos);
}

unsigned UnoPlayer::getNumofCards()
{
	return numCards;
}

std::string UnoPlayer::getPlayerName()
{
	return _name;
}