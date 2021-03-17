// TheSelectionProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SelectionSolution.h"
#include <iostream>
using namespace std;
int main()
{
	
    int size;
	int index;
	int* arr;
	cin >> size >> index;
	int number=0;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> number;
		arr[i] = number;
	}
	cout << endl;
	SelectionSolution obj(arr, size, index);
	cout << obj.selectionWithInsertionSort()<<endl;
	cout << obj.selectionWithSelect()<<endl;
}
