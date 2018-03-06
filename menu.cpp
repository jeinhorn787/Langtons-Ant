/***********************************************************************************************
** Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description: This is the implementation file for my menu.  It only has 2 options, to either
do a user generated Langton Ant, or to Quit.  The returned number
*************************************************************************************************/

#include"menu.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int menu()
{
	//int holds the choice of the user
	int choice;

	cout << "1: User Generated Langton Ant" << endl;
	cout << "2: Quit" << endl;

	cout << "Please enter a number, either 1 or 2, for you choice." << endl;
	//makes sure user enters positive integer
	choice = getUnsignedInt();
	//while the user enters anything number lower than 1
	//or any number higher than 2
	while (choice <= 0 || choice > 2)
	{
		cout << "Error. Please choose either 1 or 2." << endl;
		choice = getUnsignedInt();
	}

		switch (choice)
		{
		case 1:
			return 1;

		case 2:
			return 2;
		}
}