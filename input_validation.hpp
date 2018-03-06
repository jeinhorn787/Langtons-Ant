/***********************************************************************************************
** Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description: This is the header file of my input validation. This is only 1 of multiple
functions I have created, but I only included one for unsigned integer because that is all that
is being used in this program.
*************************************************************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP
#include <string>
using std::string;

int getUnsignedInt();
bool isUnsignedInt(string);
#endif
