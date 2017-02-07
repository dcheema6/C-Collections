
#pragma warning(disable:4996)
#ifndef UnoCard_h
#define UnoCard_h

#include<iostream>

using namespace std;

class UnoCard {
public:
	enum Color { Red, Blue, Green, Yellow };
	enum Value { One, Two, Three, Four, Five };
	UnoCard();
	UnoCard(Color color, Value value);
	~UnoCard();
	friend bool operator==(const UnoCard card1, const UnoCard card2);//Overloaded Operators
	friend ostream& operator<<(ostream& out, const UnoCard card);
	friend bool operator>(const UnoCard card1, const UnoCard card2);
	friend bool operator<(const UnoCard card1, const UnoCard card2);
private:
	Color _color;
	Value _value;
};

inline bool operator==(const UnoCard card1, const UnoCard card2)
{
	if (card1._value == card2._value)
	{
		return true;
	}
	else if (card1._color == card2._color)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline ostream& operator<<(ostream& out, UnoCard card)
{
	string col, val;
	switch (card._color)
	{
	case 0:
		out << "Red";
		break;
	case 1:
		out << "Blue";
		break;
	case 2:
		out << "Green";
		break;
	case 3:
		out << "Yellow";
		break;
	default:
		out << "check your code for error";
		break;
	}
	switch (card._value)
	{
	case 0:
		out << "-1";
		break;
	case 1:
		out << "-2";
		break;
	case 2:
		out << "-3";
		break;
	case 3:
		out << "-4";
		break;
	case 4:
		out << "-5";
		break;
	default:
		out << "check your code for error";
		break;
	}
	return out;
}

inline bool operator>(const UnoCard card1, const UnoCard card2)
{
	if (card1._value > card2._value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool operator<(const UnoCard card1, const UnoCard card2)
{
	if (card1._value < card2._value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif