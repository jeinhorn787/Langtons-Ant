/***********************************************************************************************
** Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description: This is the main file.  The menu first pops up.  If the user hits 1, the Langton
Ant begins.  The menu will pop up at the end to see if they want to play again or Quit.
*************************************************************************************************/

#include "menu.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main()
{
	int choice = menu();
	
	//if the user wants to play.
	//they can also play again at the end of the game
	while (choice == 1)
	{
		//int variables to hold the user entered row size
		//column size, the x coord of the ant and
		//the y coord of the ant.  The accum variable
		//keeps track of what step the ant is on
		int row, col, step, rsize, csize, accum = 0;

		cout << "First, please enter a positive integer from 2 to 80"
			" for the row size." << endl;
		//checks for positive integer
		rsize = getUnsignedInt();
		//user has to enter at least 2 rows and at most
		//80 rows
		while (!(isRange(rsize, 80, 2)))
		{
			cout << "Error. Out of range." << endl;
			cout << "Please enter a positive integer from 2 to 80." << endl;
			rsize = getUnsignedInt();
		}

		cout << "Next, please enter a positive integer from 2 to 80"
			" for the colmun size." << endl;
		//checks for positive integer
		csize = getUnsignedInt();
		//the user has to enter at least 2 columns and at most
		//80 columns
		while (!(isRange(csize, 80, 2)))
		{
			cout << "Error. Out of range." << endl;
			cout << "Please enter a positive integer from 2 to 80." << endl;
			csize = getUnsignedInt();
		}

		cout << "Please place the ant on the board by first entering it's x-coordinate."
			"  Enter a positive integer from 0 to " << rsize - 1 << "." << endl;
		//checks for positive integer
		row = getUnsignedInt();
		//user has to enter at least 0 and at most
		//1 less than the row size
		while (!(isRange(row, rsize - 1, 0)))
		{
			cout << "Error. Out of range." << endl;
			cout << "Please enter a positive integer from 0 to " << rsize - 1;
			cout << "." << endl;
			row = getUnsignedInt();
		}

		cout << "Now please enter it's y-coordinate.  Enter a positive integer from 0"
			" to " << csize - 1 << "." << endl;
		//checks for positive integer
		col = getUnsignedInt();
		//user has to enter at least 0 and at most
		//1 less than the column size
		while (!(isRange(col, csize - 1, 0)))
		{
			cout << "Error. Out of range." << endl;
			cout << "Please enter a positive integer from 0 to " << csize - 1;
			cout << "." << endl;
			col = getUnsignedInt();
		}

		cout << "Please enter a positive integer form 0 to 200 for the steps"
			" the ant will take." << endl;
		//checks for positive integer
		step = getUnsignedInt();
		//user has to enter at least 1 step and at most
		//200 steps
		while (!(isRange(step, 200, 1)))
		{
			cout << "Error. Out of range." << endl;
			cout << "Please enter a positive integer from 1 to 200." << endl;
			step = getUnsignedInt();
		}

		//dynamic allocation of a 2D array using the user entered
		//row size and column size
		char **arry = new char*[rsize];
		for (int row = 0; row < rsize; row++)
			arry[row] = new char[csize];

		//new Board and Ant objects using the 2D array,
		//the row and column size and
		//the ants first coords
		Board *board = new Board(arry, rsize, csize);
		Ant ant(board, row, col);

		//keeps going until the last step is reached
		while (accum < step)
		{
			accum += 1;

			//int variables to hold the ants coords before it moves
			int arow = ant.getRow();
			int acol = ant.getCol();
			//uses the coords to move the ant
			ant.moveAnt(arow, acol);

			//prints a board with an ant on it
			printToScreen(board, ant);

			//int variables hold the ants updates coords
			//these will be used to let the user know where
			//exactly the ant is
			int newRow = ant.getRow();
			int newCol = ant.getCol();

			cout << "This is step " << accum << "." << endl;
			cout << "The ant is at position " << newRow << ", "
				<< newCol << endl;
			cout << "Please hit enter for the next step." << endl;

			//user must hit enter to move onto the next step
			cin.get();
		}

		//frees the space used for the dynamically allocated 2D array
		for (int row = 0; row < rsize; row++)
			delete[] arry[row];
		delete[] arry;

		//the menu pops back up where the user can play again or quit
		choice = menu();
	}
	
	//if the user hits Quit on the menu, program terminates
	if (choice == 2)
		return 0;
}