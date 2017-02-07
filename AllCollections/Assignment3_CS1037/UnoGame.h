#pragma once
#ifndef UnoGame_h
#define UnoGame_h

#include"UnoPlayer.h"
#include"Queue.h"
#include"Stack.h"
#include"Bag.h"
#include<iostream>

class UnoGame {
private:
	UnoPlayer* player;//Someone can can make more players dynamically using arrays in the constructor
	Stack <UnoCard> faceUp;
	Queue <UnoCard> faceDown;
	Bag <UnoCard> bag;
public:
	UnoGame();
	~UnoGame();//destroctors are always em
	void play();
};


#endif