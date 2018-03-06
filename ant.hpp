/************************************************************************************
**Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description:  This is the header file for the class Ant.
************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "board.hpp"


class Ant
{
private:
	Board* board;
	int xcoord, ycoord, direction;

public:
	Ant(Board*, int, int);
	int getRow();
	int getCol();
	void moveAnt(int, int);
};

#endif
