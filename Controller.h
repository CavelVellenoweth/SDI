#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Controller
{
public:
	int convertIntUserInput(string str);
	int convertCharUserInput(string str);
	void checkUserInput(string& input, int type);
	string getUserInput(int type);
	bool isDigits(string& str);
	//this is public because the input needs to be checked if it contains only digits before it can be converted to an int in the main.
private:
	bool containsInvalidFilename(string& str);
};
