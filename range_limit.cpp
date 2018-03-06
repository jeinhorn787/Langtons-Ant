/***********************************************************************************************
** Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description: This is the implementation file for my range limimt function.  If the user enters
anything lower than the min, it returns false.  If the user enters anything more than the max, it 
returns false.
*************************************************************************************************/

#include"range_limit.hpp"
#include<iostream>
using std::cout;
using std::endl;

bool isRange(int input, int max, int min)
{
	if (input > max)
		return false;
	if (input < min)
		return false;

	return true;
}