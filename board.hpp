/******************************************************************************************
** Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description: This is the header file for the class Board.
*****************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP


class Board
{
private:
	char **board;
	int rowSize, colSize;

public:
	Board(char**, int, int);
	int getColSize();
	int getRowSize();
	char getColor(int, int);
	void changeColor(int, int);
	bool isWall(int, int);
};
#endif