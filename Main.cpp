#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Controller.h"
#include "Model.h"
#include "View.h"

using namespace std;
int main(int argc, char* argv[])
{
	Controller control;
	View view;
	Model model;

	//a copy of the vector in alphabetical and numerical(Length) order are both stored to make the binary search function for both character searches and length searches
	vector<string> alphabeticalvec;
	vector<string> numericalvec;

	//the tempvec will store the results of the users searches temporarily
	vector<string> tempvec;

	string temp;
	int num;
	char character;

	alphabeticalvec = model.readFile();
	numericalvec = alphabeticalvec;
	model.sortVector(alphabeticalvec, 0);
	model.sortVector(numericalvec, 1);
	view.displayVector(alphabeticalvec);
	while (temp != "0")
		//loops until 0 is entered by the user
	{
		view.writeline("Enter A Character Or Length To Search For (Enter 0 to exit)");
		temp = control.getUserInput(2);
		if (control.isDigits(temp))
		{
			num = control.convertIntUserInput(temp);
			tempvec = model.searchVector(numericalvec, num);
			model.sortVector(tempvec, 0);
			//the tempvec is sorted into alphabetical order after a length search is done to make the results look neater, this is done because the tempvec will be in numerical order before the sort.
		}
		else
		{
			character = control.convertCharUserInput(temp);
			tempvec = model.searchVector(alphabeticalvec, character);
		}
		view.displayVector(tempvec);
	}
	model.writeFile(alphabeticalvec);
	return 0;
}
