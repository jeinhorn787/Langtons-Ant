/***********************************************************************************************
** Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description: This is the implementation file for the printer function.  By using a pointer to
Board and an Ant object, it can print an Ant on a Board.
*************************************************************************************************/

#include "antPrint.hpp"
#include <iostream>
using std::cout;
using std::endl;

void printToScreen(Board* b, Ant a)
{
	//int variables to hold the ants coordinates and
	//to hold the boards correct row and column sizes
	int antRow = a.getRow();
	int antCol = a.getCol();
	int rowSize = b->getRowSize();
	int colSize = b->getColSize();

	//each element will be filled with a color received from Board
	//if the index reaches the ants x and y coordinats
	//it will print the ant on the screen
	//if not,it will get a color from Board to print in the followin elements
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			//if ants coords match the index
			if (i == antRow && j == antCol)
				cout << '@';

			//if there is no ant in the index
			else
				cout << b->getColor(i, j);
		}

		cout << endl;
	}
}