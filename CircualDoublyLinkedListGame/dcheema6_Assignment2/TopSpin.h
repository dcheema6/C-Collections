#ifndef TopSpin_h
#define TopSpin_h
#include "CircularDoublyLinkedList.h"
#include<ostream>

using std::ostream;

class TopSpinADT {
public:
	// shifts the pieces 1 to the left
	virtual void shiftLeft() = 0;
	//shifts the pieces 1 to the right
	virtual void shiftRight() = 0;
	//reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
	// 1,4,3,6 we will have 6,3,4,1
	virtual void spin() = 0;
	//checks to see if the puzzle is solved that is to say the pieces are in numerical order 1 - 20
	virtual bool isSolved() = 0;
};

class TopSpin : public TopSpinADT
{
private:
	unsigned int _size, _spinsize;
	CDLL<int> game;
public:
	TopSpin(unsigned size, unsigned spinsize);
	~TopSpin();
	void spin();
	void shiftLeft();
	void shiftRight();
	bool isSolved();

	void addHead(int item);
	void removeHead();
	void removeTail();
	int retrieveHead() const;
	int retrieveTail() const;
	void add(unsigned int n, int item);
	void remove(unsigned int n);
	void replace(unsigned int n, int item);
	bool isEmpty() const;
	unsigned int size() const;
	friend ostream& operator<< (ostream& os, const TopSpin& ts);
};

inline ostream& operator<< (ostream& os, const TopSpin& ts)
{
	os << "[ ";
	for (unsigned i = 1; i <= ts._spinsize; i++)
	{
		os << ts.game.retrieve(i) << ' ';
	}
	os << "] ";
	for (unsigned i = ts._spinsize + 1; i <= ts._size; i++)
	{
		os << ts.game.retrieve(i) << ' ';
	}
	os << '\n';
	return os;
}

#endif