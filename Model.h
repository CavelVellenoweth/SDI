#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Model
{
	public:
		vector<string> searchVector(vector<string>& vec, char character);
		vector<string> searchVector(vector<string>& vec, int length);
		void sortVector(vector<string>& vec, bool NumericSort);
		vector<string> readFile();
		void writeFile(vector<string> vec);

	private:
		struct totals;
		void incrementCounter(char a, totals& tot);
		void incrementCounter(int x, totals& tot);		
		string lowerCase(string line);
		char lowerCase(char character);
		int findInvalid(string& str);
		bool containsInvalidText(string& str);
		void parseLine(string line, vector<string>& vec);		
		void quickSortAlpha(vector<string>& vec, int l, int r);
		void quickSortNumeric(vector<string>& vec, int l, int r);
		vector<string> binarySearch(vector<string>&vec, int current, int min, int max, char character);
		vector<string> binarySearch(vector<string>&vec, char character);
		vector<string> binarySearch(vector<string>&vec, int current, int min, int max, int length);
		vector<string> binarySearch(vector<string>&vec, int length);
		
};