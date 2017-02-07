#include"UnoGame.h"
#include<iostream>

UnoGame::UnoGame() :bag(40)//default bag size is 20 we need 40
{
	for (unsigned i = 0; i < 2; i++)//setting up game
	{
		for (unsigned i = 0; i < 4; i++)
		{
			for (unsigned j = 0; j < 5; j++)
			{
				UnoCard c(static_cast<UnoCard::Color>(i), static_cast<UnoCard::Value>(j));//casting values to card using position in enums
				bag.add(c);
			}
		}
	}

	while (!bag.isEmpty())
	{
		faceDown.enqueue(bag.getOne());//faceDown gets the card being removed from bag till the bag is empty
	}

	player = new UnoPlayer[3];//creating 3 players

	for (unsigned j = 0; j < 3; j++)
	{
		for (unsigned i = 1; i <= 7; i++)
		{
			player[j].addCard(faceDown.dequeue());//distributing cards to players
		}
	}
	faceUp.push(faceDown.dequeue());//adding one card to faceup pile
}

UnoGame::~UnoGame()
{
	cout << "\nThis Ends Now!\n\n";
}

void UnoGame::play()
{
	std::cout << "Welcome to UNO\n\nGame Start...\nFace Up Pile: " << faceUp.peek() << "\n_____________________________________\n\n";
	bool gameFinished = false;
	do// do while loop will continue untill game is finished ie gamefinished = true;
	{
		for (unsigned i = 0; i < 3; i++)
		{
			if (!faceDown.isEmpty())// if face down pile is not empty
			{
				std::cout << "It is Player " << i + 1 << "'s turn:\n";
				int cardMatch = player[i].cardMatch(faceUp.peek());//cardmatch checks if player has any matching card to face up pile top.
																// it retuns 0 if not or returns [position of card in players hand] postions start at 1
				if (cardMatch == 0)
				{
					std::cout << "Player " << i + 1 << " did not find a match.They drew a card\n_____________________________________\n";
					player[i].addCard(faceDown.dequeue());//player takes card id no matching card found
				}
				else
				{
					faceUp.push(player[i].retrieveCard(cardMatch));//matching card is pushed on to top of faceup pile
					std::cout << "Player " << i + 1 << " found a match! TheyPlayed" << faceUp.peek() << "\n_____________________________________\n";
					player[i].removeCard(cardMatch);// player matching card is then removed.. However this is not how it works in realy life lol.
				}
				if (player[i].getNumofCards() == 1)//if player has 1 card left
				{
					std::cout << "\tPlayer " << i + 1 << " yells UNO!\n_____________________________________\n";
				}
				else if (player[i].getNumofCards() == 0)//if player have no cards left
				{
					std::cout << "************Player " << i + 1 << " Won! What a lame assignment(JK)************\n";
					gameFinished = true;//game is finished
				}
			}
			else if(faceDown.isEmpty())// if face down pile is empty
			{
				UnoCard temp = faceUp.pop();//Top card from faceup pile is saved
				while (!faceUp.isEmpty())//all other cards are transfered to facedown pile until faceup is empty. This works in exact manner as in real life thax to Jordan.
				{
					faceDown.enqueue(faceUp.pop());//Tranfer of a card
				}
				faceUp.push(temp);// saved card is then made top of faceup pile again
				std::cout << "The deck has been repopulated\n_____________________________________\n";
			}
		}
	} while (!gameFinished);// loop ends when game is finished
}