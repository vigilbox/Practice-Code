// Merge Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

void merge(vector<int> A, int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(n1 + 1);
	vector<int> R(n2 + 1);
	
	for (i = 0; i < n1; i++)
	{
		L[i] = A[p + i - 1];
	}

	for (j = 0; j < n2; j++)
	{
		R[j] = A[q + j];
	}

	L[n1] = 99999;
	R[n2] = 99999;
	i = 0;
	j = 0;

	for (k = p; k < r; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else 
		{
			A[k] = R[j];
			j++;
		}

	}
}

void merge_sort(vector<int> v, int p, int r)
{
	int q;
	if (p < r)
	{
		q = floor((p + r) / 2);
		merge_sort(v, p, q);
		merge_sort(v, q + 1, r);
		merge(v, p, q, r);
	}
}

int main()
{
	vector<int> num;
	string console_input;
	int len;
	cout << "Welcome to Merge Sort. Please enter some numbers for sorting.\n";

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

	len = num.size();
	merge_sort(num, 0, len);
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
