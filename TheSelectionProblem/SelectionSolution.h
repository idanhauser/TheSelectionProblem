#pragma once

class SelectionSolution
{
private:
	int* _array;
	int* _OperationArray;
	int _size;
	int _indexToFind;
	SelectionSolution(SelectionSolution& other);
	void operator=(SelectionSolution& other);
public:
	SelectionSolution(int* arr, int size, int idxToFind);
	~SelectionSolution();
	int selectionWithInsertionSort();
	int selectionWithSelect();
	int selectionWithFifthAlgo();
	int fifthAlgo(int size);
	void copyArr();
	int Select(int left, int right, int i);
	void swapPositions(int* pFirst, int* pSecond);
	int partition(int left, int right);
	void bubbleSort(int size);
	
};


