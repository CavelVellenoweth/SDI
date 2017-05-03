#include <vector>
#include <iostream>
#include <string>
#include "View.h"
using namespace std;

void View::displayVector(vector<string>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << '\n';
}
void View::writeline(string message)
{
	cout << '\n' << message << '\n';
}