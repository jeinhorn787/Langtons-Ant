/********************************************************************************************
**Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description: This is the implementation for the Board class. It stores the pointer to an 
array and the boards row and column size.  It will set a color for a square, change the color
of a square, and use the ants current coords to check if it is out of bounds.
**********************************************************************************************/

#include"board.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//constructor sets pointer to 2D array and sets row and column size
Board::Board(char** b, int rs, int cs)
{
	board = b;
	rowSize = rs;
	colSize = cs;
}

//returns column size
int Board::getColSize()
{
	return colSize;
}

//returns row size
int Board::getRowSize()
{
	return rowSize;
}

//returns the color of a square
//if the square has no color, it will default it to white
char Board::getColor(int x, int y)
{
	char el = board[x][y];

	//defaults empty space to white
	if (el != ' ' && el != '#')
		return ' ';

	return el;
}

//flips to either white or black depending on what is there
void Board::changeColor(int x, int y)
{
	char current = getColor(x, y);
	
	//white to black
	if (current == ' ')
		board[x][y] = '#';

	//black to white
	else
		board[x][y] = ' ';

}

//using the ants current coords, it will make sure
//it is not out of bounds.  If it is, it will return true
bool Board::isWall(int x, int y)
{
	
	if (x < 0)
		return true;
	//if x coord exceeds row size
	if (x > rowSize - 1)
		return true;

	if (y < 0)
		return true;
	//if y coord exceeds column size
	if (y > colSize - 1)
		return true;

	return false;
}