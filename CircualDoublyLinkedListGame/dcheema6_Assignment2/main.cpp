#include"TopSpin.h"
#include"CircularDoublyLinkedList.h"
#include<iostream>

using std::cout;
using std::cin;

void main()
{
	TopSpin game(20,4);
	cout << "Enter the number of random moves you would like to initialize the puzzle with: ";
	int mov;
	cin >> mov;
	for (int i = 0; i < mov; i++)
	{
		game.shiftLeft();
		game.spin();
	}
	while (game.isSolved() == false)
	{
		cout << "Please choose from the following options enter your choice by entering the corresponding number : \n1. Shift Left\n2. Shift Right\n3. Spin\n4. Quit\n" << game;
		int choice;
		cin >> choice;
		int shifts;
		switch (choice)
		{
		case 1:
			cout << "Enter the number of Shifts: ";
			cin >> shifts;
			while (shifts != 0)
			{
				game.shiftLeft();
				shifts--;
			}
			break;
		case 2:
			cout << "Enter the number of Shifts: ";
			cin >> shifts;
			while (shifts != 0)
			{
				game.shiftRight();
				shifts--;
			}
			break;
		case 3:
			game.spin();
			break;
		case 4:
			cout << "Thank you for playing\n";
			//return;
			break;
		default:
			cout << "Invalid choice entered!\n";
			break;
		}
	}
	cout << game << "You have solved the puzzle. Good Job!\n";
	return;
}