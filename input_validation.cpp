/***********************************************************************************************
** Program Name: Project1 (Langton Ant)
** Author: Jeremy Einhorn
** Date: July 7, 2017
** Description: This is the implementation file for my input validation function.
*************************************************************************************************/

#include "input_validation.hpp"
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::remove;
using std::atoi;

int getUnsignedInt()
{
	//string variable to store input in which will be used to check for unsigned int
	//int variable to hold converted string to integer
	string input;
	int uint;

	//do while loops continues until unsigned integer is input
	do 
	{
		//getline grabs everything the user enters until enter is pressed by user
		getline(cin, input);

		//the following code taken from 
		//https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		//end of copied code

		//if it is not an unsigned int, an error message will tell the user to
		//try again
		if (!(isUnsignedInt(input)))
			cout << "Error. Please enter a positive integer." << endl;

	} while (!(isUnsignedInt(input)));

	uint = atoi(input.c_str());

	return uint;
}

//checks input string to make sure all chars are digits
bool isUnsignedInt(string input)
{	
	bool message;

	for (int index = 0; index < input.size(); index++)
	{
		if (isdigit(input[index]))
			message = true;
		//immediately return false if anything other than a number
		//is found
		else
			return false;
	}

	return message;
}