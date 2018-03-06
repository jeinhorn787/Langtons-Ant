/*********************************************************************************************
** Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description: This is the implementation file for the Ant class.  The ant stores it's 
coordinates as well as moves itself using a pointer to a Board.
**********************************************************************************************/

#include "ant.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//constructor takes a pointer to a Board, sets its x and y coords
//and sets it initial direction
//DIRECTIONS: 1 = UP, 2 = DOWN, 3 = LEFT, 4 = RIGHT
Ant::Ant(Board* b, int x, int y)
{
	board = b;
	xcoord = x;
	ycoord = y;
	direction = 1;
}

//returns it's x-coord
int Ant::getRow()
{
	return xcoord;
}

//returns it's y-coord
int Ant::getCol()
{
	return ycoord;
}

//the ants current coords are passed, it first looks at what color square the ant is in
//depending on the color, it turns itself either rigt or left
//the board then uses the ants coords to switch the correct square color
//the ant takes a step in the direction it is facing
//if the ant's updated coords are outside of the board, the ant is placed back in its
//original position, but it's direction is now the opposite of what it was before it moved
//it takes a step in that direction to keep it in bounds
void Ant::moveAnt(int x, int y)
{
	//if the space is white
	if (board->getColor(x, y) == ' ')
	{	
		//turns right to face right
		if (direction == 1)
			direction = 4;
		//turns right to face left
		else if (direction == 2)
			direction = 3;
		//turns right to face up
		else if (direction == 3)
			direction = 1;
		//turns right to face down
		else if (direction == 4)
			direction = 2;
	} 

	//if the space is black
	else 
	{
		//turns left to face left
		if (direction == 1)
			direction = 3;
		//turns left to face right
		else if (direction == 2)
			direction = 4;
		//turns left to face down
		else if (direction == 3)
			direction = 2;
		//turns left to face up
		else if (direction == 4)
			direction = 1;
	}

	//uses current coords to change the squares color
	board->changeColor(x, y);

	//if facing up, move up 1
	if (direction == 1)
		xcoord = x - 1;
	//if facing down, move down 1
	if (direction == 2)
		xcoord = x + 1;
	//if facing left, move left 1
	if (direction == 3)
		ycoord = y - 1;
	//if facing right, move right 1
	if (direction == 4)
		ycoord = y + 1;

	//if the ants current coords are out of bounds
	if (board->isWall(xcoord, ycoord))
	{
		//put it back on the board and move it down 1
		//change its direction to down
		if (direction == 1)
		{
			xcoord += 2;
			direction = 2;
		}

		//place it back on board and move it up 1
		//change direction to up
		else if (direction == 2)
		{
			xcoord -= 2;
			direction = 1;
		}

		//place it back on board and move it right 1
		//change diretion to right
		else if (direction == 3)
		{
			ycoord += 2;
			direction = 4;
		}

		//place it back on board and move left 1
		//change direction to left
		else if (direction == 4)
		{
			ycoord -= 2;
			direction = 3;
		}
	}
}