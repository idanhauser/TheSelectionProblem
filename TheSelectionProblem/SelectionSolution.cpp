#include "SelectionSolution.h"
#include <algorithm>
using namespace std;
SelectionSolution::SelectionSolution(int* arr, int size, int idxToFind):_array(arr), _size(size), _indexToFind(idxToFind),_OperationArray(new int[size])
{
}

SelectionSolution::~SelectionSolution()
{
    delete[] _OperationArray;
}

int SelectionSolution::selectionWithInsertionSort()
{
    int pCurrent;
    int writeIdx = 0;
    copyArr();
    for (int i = 1; i < _size; ++i)
    {
        pCurrent = _OperationArray[i];
        writeIdx = i - 1;
        while ((writeIdx >= 0) && (_OperationArray[writeIdx] > pCurrent))
        {
            _OperationArray[writeIdx+1] = _OperationArray[writeIdx];
            writeIdx--;
        }
        _OperationArray[writeIdx+1] = pCurrent;
    }

    return _OperationArray[_indexToFind-1];
}

int SelectionSolution::selectionWithSelect()
{
    copyArr();
   return Select(0, _size - 1, _indexToFind);
}

void SelectionSolution::copyArr()
{

	for (int i = 0; i < _size; i++)
	{
		_OperationArray[i] = _array[i];
	}
}

int SelectionSolution::Select(int left, int right, int i)
{
    int pivot;
    int leftPart;
	
    pivot =partition(left, right);
    leftPart = pivot - left + 1;
	if(i==leftPart)
	{
        return _OperationArray[pivot];
	}
	if(i<leftPart)
	{
        return Select(left, pivot - 1, i);
	}
    else
    {
        return Select(pivot + 1, right, i - leftPart);
    }
}

void SelectionSolution::swapPositions(int* pFirst, int* pSecond)
{
    int temp = *pFirst;
    *pFirst = *pSecond;
    *pSecond = temp;
}

int SelectionSolution::partition(int left, int right)
{
    int temp;
    int pivot = left; // pivot 
    int indexToCompare = right; // Index of smaller element and indicates the right position of pivot found so far

    while (pivot!=indexToCompare)
    {
	    if(pivot<indexToCompare)
	    {
		    if(_OperationArray[pivot]>_OperationArray[indexToCompare])
		    {
                swapPositions(&_OperationArray[pivot], &_OperationArray[indexToCompare]);
                 temp = indexToCompare;
                indexToCompare = pivot + 1;
                pivot = temp;
		    }
            else
            {
                indexToCompare--;
            }
	    }
        else if (pivot>indexToCompare)
        {
	        if(_OperationArray[pivot]<_OperationArray[indexToCompare])
	        {
                swapPositions(&_OperationArray[pivot], &_OperationArray[indexToCompare]);
                 temp = indexToCompare;
                indexToCompare = pivot - 1;
                pivot = temp;
	        }
            else
            {
                indexToCompare++;
            }
     
        }
    }
    
           return pivot;
}



