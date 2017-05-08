#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Model.h"
#include "Controller.h"
#include "View.h"
using namespace std;
Controller control;
View view;
int counter = 0;
struct Model::totals
	//the purpose of this struct is to keep a running total of the amount of words beginning with each letter and the number of words of lengths 1-10
{
	char letters[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int letterCount[26] = { 0 };
	vector<int> lengthCount = { 0 };
}total;
//total is declared when an instance of model is declared and will contain the totals for the other functions to access.
vector<string> Model::binarySearch(vector<string>&vec, int current, int min, int max, char character)
{
	counter++;
	// the same as the following binary search calls but will check if the beggining letter of the word is the same as the desired one. check the other instances of the binary search for an explanation
	//of it's workings
	vector<string> vec2;
	if (vec[current].front() == character)
	{
		if (current == 0)
		{
			int i = current;
			while (vec[i].front() == character)
			{
				vec2.push_back(vec[i]);
				i++;
				if (i >= vec.size())
					break;
			}
			return vec2;
		}
		if (vec[current - 1].front() != character)
		{
			int i = current;
			while (vec[i].front() == character)
			{
				vec2.push_back(vec[i]);
				i++;
				if (i >= vec.size())
					break;
			}
			return vec2;
		}
	}
	if (vec[current].front() < character)
	{
		if (min != current)
		{
			min = current;
			current = (current + max) / 2;
			vec2 = binarySearch(vec, current, min, max, character);
		}
		return vec2;
	}
	if (vec[current].front() >= character)
	{
		max = current;
		current = (min + current) / 2;
		if (max != min)
		{
			vec2 = binarySearch(vec, current, min, max, character);
		}
		return vec2;
	}
}
vector<string> Model::binarySearch(vector<string>&vec, char character)
{
	counter++;
	// the same as the following binary search calls but will check if the beggining letter of the word is the same as the desired one. check the other instances of the binary search for an explanation
	//of it's workings
	vector<string> vec2;
	int min = 0;
	int max = vec.size() - 1;
	int current = (min + max) / 2;
	if (vec[current].front() == character)
	{
		if (current == 0)
		{
			int i = current;
			while (vec[i].front() == character)
			{
				vec2.push_back(vec[i]);
				i++;
				if (i >= vec.size())
				break;
			}
			return vec2;
		}
		if (vec[current - 1].front() != character)
		{
			int i = current;
			while (vec[i].front() == character)
			{
				vec2.push_back(vec[i]);
				i++;
				if (i >= vec.size())
					break;
			}
			return vec2;
		}
	}
	if (vec[current].front() < character)
	{
		min = current;
		current = (current + max) / 2;
		vec2 = binarySearch(vec, current, min, max, character);
		return vec2;
	}
	if (vec[current].front() >= character)
	{
		max = current;
		current = (min + current) / 2;
		vec2 = binarySearch(vec, current, min, max, character);
		return vec2;
	}
}
vector<string> Model::binarySearch(vector<string>&vec, int current, int min, int max, int length)
{
	//this is the instance of binarysearch that is recursive
	vector<string> vec2;
	if (vec[current].length() == length)
	{
		if (current == 0)
		{
			int i = current;
			while (vec[i].length() == length)
			{
				vec2.push_back(vec[i]);
				i++;
				if (i >= vec.size())
					break;
			}
			return vec2;
		}
		if (vec[current - 1].length() != length)
		{
			int i = current;
			while (vec[i].length() == length)
			{
				vec2.push_back(vec[i]);
				i++;
				if (i >= vec.size())
					break;
			}
			return vec2;
		}
	}
	if (vec[current].length() < length)
	{
		if (min != current)
			//if min is the same value as current then the length being searched for does not exist in the vector. this instance will spot lengths that are shorter than any length that exists in the vector
		{
			min = current;
			current = (current + max) / 2;
			vec2 = binarySearch(vec, current, min, max, length);
		}
		return vec2;
	}
	if (vec[current].length() >= length)
	{
		max = current;
		current = (min + current) / 2;
		if (max != min)
			//if min is the same value as max then the length being searched for does not exist in the vector. this instance will spot lengths that are longer than any length that exists in the vector
		{
			vec2 = binarySearch(vec, current, min, max, length);
		}
		return vec2;
	}
}
vector<string> Model::binarySearch(vector<string>&vec, int length)
{
	//this instance of binary search is the one that will be called by the user and is only used once per call
	vector<string> vec2;

	int min = 0;
	int max = vec.size() - 1;
	int current = (min + max) / 2;
	if (vec[current].length() == length)
		//is the length of the current word the desired length
	{
		if (current == 0)
			//if the current word is the first word in the array it also passes.
		{
			int i = current;
			while (vec[i].length() == length)
			{
				vec2.push_back(vec[i]);
				i++;
				if (i >= vec.size())
					//this is so that if the vector is only countains 1 word it wont crash by looking for something in the next position in the vector
					break;
			}
			return vec2;
		}
		if (vec[current - 1].length() != length)
			//if the word is the desired length it checks if the word before it is also the desired length to try and find the first instance of a word being the desired length in the vector.
		{
			int i = current;
			while (vec[i].length() == length)
			{
				//adds all the words that are of the desired length into the new array
				vec2.push_back(vec[i]);
				i++;
				if (i >= vec.size())
					break;
			}
			return vec2;
		}
	}
	if (vec[current].length() < length)
	{
		//if the word in the current position is shorter than the desired length the minimum position of the desired number will be set to the current position
		//and the new position in the vector that will be searched will be the halfway point between the new min and max effectively reducing 
		//the number of potential positions by half each instance.
		min = current;
		current = (current + max) / 2;
		vec2 = binarySearch(vec, current, min, max, length);
		return vec2;
	}
	if (vec[current].length() >= length)
	{
		//if the word in the current position if longer than the desired length the maximum value will be reduced instead.
		max = current;
		current = (min + current) / 2;
		vec2 = binarySearch(vec, current, min, max, length);
		return vec2;
	}
}

void Model::quickSortAlpha(vector<string>& vec, int l, int r)
{
	//sorts alphabetically(A-Z)
		int i = l, j = r;
		string tmp;
		string pivot = vec[(l + r) / 2];
		//pivot is set halfway between the leftmost and rightmost positions
		while (i <= j)
			//loops until i and j pass eachother
		{
			while (vec[i] < pivot)
				//checks the numbers from the left of the pivot to the right to find a number that is greater than the pivot
				i++;
			while (vec[j] > pivot)
				//checks the numbers from the right of the pivot to the left to find a number that is smaller than the pivot
				j--;
			if (i <= j) 
				//if i is less than or equal to j the values of i and j are swapped
			{
				tmp = vec[i];
				vec[i] = vec[j];
				vec[j] = tmp;
				i++;
				j--;
			}
		};

		if (l < j)
			//if the current value l is less than the value of j, j becomes the rightmost position
			quickSortAlpha(vec, l, j);
		if (i < r)
			//if the current value of i is less than the value of r, i becomes the leftmost position
			quickSortAlpha(vec, i, r);
}
void Model::quickSortNumeric(vector<string>& vec, int l, int r)
{
	//sorts numerically by length(shortest - Longest)
		int i = l, j = r;
		string tmp;
		int pivot = vec[(l + r) / 2].length();

		while (i <= j)
		{
			while (vec[i].length() < pivot)
				i++;
			while (vec[j].length() > pivot)
				j--;
			if (i <= j) {
				tmp = vec[i];
				vec[i] = vec[j];
				vec[j] = tmp;
				i++;
				j--;
			}
		};

		if (l < j)
			quickSortNumeric(vec, l, j);
		if (i < r)
			quickSortNumeric(vec, i, r);
}
void Model::sortVector(vector<string>& vec, bool NumericSort)
{
	if (vec.size() > 1)
		//only tries to sort the vector if it contains more than 1 entry
	{
		if (NumericSort == 0)
			//numericsort states whether the vector is being sorted in numerical order(1) or alphabetical order(0)
		{
			quickSortAlpha(vec, 0, vec.size() - 1);
		}
		else quickSortNumeric(vec, 0, vec.size() - 1);
	}
}
vector<string> Model::searchVector(vector<string>& vec, char character)
{
	counter = 0;
	vector<string> temp;
	if (vec.size() > 0)
		//only tries to search the vector if it contains atleast 1 entry
	{
		
		temp = binarySearch(vec, lowerCase(character));
		
	}

	return temp;
}
vector<string> Model::searchVector(vector<string>& vec, int length)
{
	vector<string> temp;
	if (vec.size() > 0)
		//only tries to search the vector if it contains atleast than 1 entry
	{
		
		temp = binarySearch(vec, length);
		
	}
	return temp;
}
string Model::lowerCase(string line)
{
	string lowercaseline;
	for (string::size_type i = 0; i<line.length(); ++i)
		lowercaseline += tolower(line[i]);
	return lowercaseline;
}
char Model::lowerCase(char character)
{
	char lowercasechar = tolower(character);
	return lowercasechar;
}
int Model::findInvalid(string& str)
{
	//returns the position of the invalid character
	int y;
	y = str.find_first_of("\/:*?<>|',.#~[]{};()+=_-!£$%^&*`¬'“”’…¸–'\"'");
	return y;
}
bool Model::containsInvalidText(string& str)
{
	//returns whether the an invalid character exists in the word
	bool x;
	x = str.find_first_of("\/:*?<>|',.#~[]{};()+=_-!£$%^&*`¬'“”’…¸–'\"'") != string::npos;
	return x;
}
void Model::incrementCounter(char a, totals& tot)
{
	for (int i = 0; i < size(tot.letters); i++)
	{
		if (tot.letters[i] == a)
		{
			tot.letterCount[i]++;
			break;
		}
	}
}
void Model::incrementCounter(int x, totals& tot)
{
	while (x > tot.lengthCount.size())
		tot.lengthCount.push_back(0);

	tot.lengthCount[x-1]++;

}
void Model::parseLine(string line, vector<string>& vec)
{
	string unparsedline;
	string parsedline;
	while (!line.empty())
	{
		if (line.find(" ") != string::npos)
			//if the line contains a space it enters this if statement
		{
			unparsedline = line.substr(0, line.find(" "));
			//unparsed line becomes set to the contents of the line up to the space
			while (containsInvalidText(unparsedline))
			{
				//removes all invalid characters from the unparsed line before continuing
				unparsedline.erase(findInvalid(unparsedline), 1);
			}
			if (!unparsedline.empty())
			{
				//converts line to lowercase only for consistency
				parsedline = lowerCase(unparsedline);
				vec.push_back(parsedline);
				incrementCounter(parsedline.front(), total);
				incrementCounter((int)parsedline.length(), total);
			}
			//erases everything from the line up to and including the first space
			line.erase(0, line.find(" ") + 1);
		}
		else
		{
			//if no spaces remain this will be the last word
			unparsedline = line.substr(0);
			while (containsInvalidText(unparsedline))
			{
				unparsedline.erase(findInvalid(unparsedline), 1);
			}
			if (!unparsedline.empty())
			{
				parsedline = lowerCase(unparsedline);
				vec.push_back(parsedline);
			}
			//erases all of the conent from the line
			line.erase();
		}
	}
}
vector<string> Model::readFile()
{
	string file;
	vector<string> vec1;
	string line;
	bool valid = false;
	while (!valid)
	{
		view.writeline("Enter The Name Of The Text File You Want To Read.");
		file = control.getUserInput(1);
		ifstream myfile(file);
		if (myfile.is_open())
		{
			valid = true;
			while (getline(myfile, line))
			{
				//parses line before continuing seperate each word from the line
				parseLine(line, vec1);
			}
			myfile.close();
		}
		else
		{
			view.writeline("Unable to open file.");
		}
	}
	return vec1;
}
void Model::writeFile(vector<string> vec)
{
	string file;
	bool valid = false;
	while (!valid)
	{
		view.writeline("Enter a Name for the saved file:");
		file = control.getUserInput(1);
		ofstream myfile(file);
		if (myfile.is_open())
		{
			valid = true;
			//writes the count of words begginning with each letter to the file
			for (int i = 0; i < size(total.letters); i++)
			{
				myfile << "Number of Words beginning with '" << total.letters[i] << "': " << total.letterCount[i] << "\n";
			}
			//writes the count of words of each length to the file
			for (int i = 0; i < size(total.lengthCount); i++)
			{
				myfile << "Number of Words that are '" << i+1 << "' Letters Long: " << total.lengthCount[i] << "\n";
			}
			myfile << "";
			myfile << "Alphabetically Sorted List : " << "\n";

			for (int i = 0; i < vec.size(); i++)
			{
				myfile << vec[i] << ' ';
			}

			myfile.close();
		}
		else
		{
			view.writeline("Unable to open file.");
		}
	}
}