#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Controller.h"
using namespace std;


int Controller::convertIntUserInput(string str)
{
	int input = stoi(str);
	return input;
}
int Controller::convertCharUserInput(string str)
{
	char input = str.front();
	return input;
}
bool Controller::isDigits(string& str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}
bool Controller::containsInvalidFilename(string& str)
{
	return str.find_first_of("\/:*?<>|") != string::npos;
}
void Controller::checkUserInput(string& input, int type)
{
	switch (type)
	{
	case 0:
		//string input not a file
		break;
	case 1:
		//filename input
		if (containsInvalidFilename(input))
		{
			cout << "do not enter invalid characters for a file name such as \/:*?<>|" << '\n';
			input = getUserInput(type);
		}
		if (input.find(".") != string::npos)
		{
			//checks if the string given has .txt at the end, and adds it if it doesn't, and removes anything after a "." if the file type isn't txt
			if (input.substr(input.find(".")) != ".txt")
			{
				input.erase(input.find("."));
				input += ".txt";
			}

		}
		else input += ".txt";
		break;
	case 2:
		//int/char input
		if (input.front() == '0' || input.front() == '1' || input.front() == '2' || input.front() == '3' || input.front() == '4' || input.front() == '5' || input.front() == '6' || input.front() == '7' || input.front() == '8' || input.front() == '9')
		{
			//checks if it is an int input then checks if the input contains only ints
			if (!isDigits(input))
			{
				cout << "If you are entering a number please only use numbers" << '\n';
				input = getUserInput(type);
			}
			break;
		}
		//changes the input to only be the front letter if it is a char input
		else input = input.front();
		break;
	}
}
string Controller::getUserInput(int type)
{
	//type being the desired input from the user e.g. int/char/string etc.
	string input;
	cin >> input;
	switch (type)
	{
	case 0:
		//string input not a file
		break;
	case 1:
		//filename input
		checkUserInput(input, type);
		break;
	case 2:
		//int/char input
		checkUserInput(input, type);
		break;
	}
	return input;
}