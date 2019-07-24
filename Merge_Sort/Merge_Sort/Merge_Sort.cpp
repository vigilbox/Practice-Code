// Merge_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
	int i, j, k;
		
	int* t = new int[high - low + 1];
	
	i = low;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= high)

	{
		if (A[i] < A[j])
		{
			*(t + k) = A[i];
			k++;
			i++;
		}
		else
		{
			*(t + k) = A[j];
			k++;
			j++;

		}
	}
// Read remaining elements in subarray A[low to mid]
	while (i <= mid)
	{
		*(t + k) = A[i];
		k++;
		i++;
	}
// Read remaining elements in subarray A[mid to high]
	while (j <= high)
	{
		*(t + k) = A[j];
		k++;
		j++;
	}
	
// Reassign sorted elements to subarray A[low to high]	
	for (i = low; i <= high; i++)
	{
		A[i] = *(t + i - low);
	}

	
	delete[] t;
}

void merge_sort(int v[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(v, low, mid);
		merge_sort(v, mid + 1, high);
		merge(v, low, mid, high);
	}

	
}

int main()
{
	int A[100], size, i=0;
	cout << "How many numbers do you wish to sort today?:\n";
	cin >> size;
	if (size > 100)
	{ 
		cout << "This program supports list sizes up to 100 elements";
		return 1;
	}
		
	cout << "Please enter the list of numbers, press enter key after each number to continue.";
	for (i = 0; i < size; i++)
	{
		cin >> A[i];
	}

	merge_sort(A, 0, size -1);
	
	cout << "Sorted List:\n";
	
	for(i = 0; i < size; i++)
	{
		cout << A[i] << "  ";
	}
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
