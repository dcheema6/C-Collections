#include"TopSpin.h"
#include<iostream>

using std::cout;
using std::cin;

TopSpin::TopSpin(unsigned size, unsigned spinsize)
{
	_size = size > 0 ? size : 20;
	_spinsize = spinsize < size && spinsize > 0 ? spinsize : 4;
	for (unsigned i = 1; i <= _size; i++)
	{
		game.addTail(i);
	}
}

TopSpin::~TopSpin()
{
	game.~CDLL();
}

void TopSpin::spin()
{
	for (unsigned i = 1; i < _spinsize / 2 + 1; i++)
	{
		if (i != (_spinsize + 1 - i)) game.swap(i, _spinsize + 1 - i);
	}
}

void TopSpin::shiftLeft()
{
	game.left();
}

void TopSpin::shiftRight()
{
	game.right();
}

bool TopSpin::isSolved()
{
	TopSpin temp(_size, _spinsize);
	unsigned num = 0;
	for (unsigned i = 1; i <= _size; i++)
	{
		if (temp.game.retrieve(i) == game.retrieve(i)) num++;
	}
	if (num == _size) return true;
	else return false;
}

void TopSpin::addHead(int item)
{
	game.addHead(item);
	_size++;
}

void TopSpin::removeHead()
{
	game.removeHead();
	_size--;
}

void TopSpin::removeTail()
{
	game.removeTail();
	_size--;
}

int TopSpin::retrieveHead() const
{
	return game.retrieveHead();
}

int TopSpin::retrieveTail() const
{
	return game.retrieveTail();
}

void TopSpin::add(unsigned int n, int item)
{
	game.add(n, item);
	_size++;
}

void TopSpin::remove(unsigned int n)
{
	game.remove(n);
	_size--;
}

void TopSpin::replace(unsigned int n, int item)
{
	game.replace(n, item);
}

bool TopSpin::isEmpty() const
{
	return game.isEmpty();
}

unsigned int TopSpin::size() const
{
	return _size;
}