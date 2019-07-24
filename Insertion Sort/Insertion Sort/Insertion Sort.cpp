// Insertion Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Insertion Sort is an O(n^2) algorithm

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int insertion_sort(vector<int> v)
{
	int j = 0;
	int i = 0;
	int key = 0;
	
	

	for (j = 1; j < v.size(); j++)
	{
		key = v[j];
		i = j - 1;
		
		while (i > -1 && v[i] > key)
		{
			v[i + 1] = v[i];
			i -= 1;
		}

		v[i + 1] = key;
	}

	cout << "Sorted List: \n";
	for (i = 0; i < v.size(); i++)
		cout << v[i] << "   ";
	cout << endl;
	return 0;
}

int main()
{
	vector<int> num;
	string console_input;
	
	cout << "Hello!, please enter some numbers for sorting.\n";
	
	while (getline(cin, console_input))
	{ 
		if (console_input == "")
			break;
		int number;
		stringstream s(console_input);
		while (s >> number)
		{
			num.push_back(number);
		}
	}

	insertion_sort(num);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
