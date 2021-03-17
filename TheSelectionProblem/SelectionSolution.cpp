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

int SelectionSolution::selectionWithFifthAlgo()
{
    copyArr();
    return Select(0, _size - 1, _indexToFind);
}

int SelectionSolution::fifthAlgo(int size)
{
	if(size<=5)
	{
        bubbleSort(size);
        return _OperationArray[_indexToFind];
	}
    else
    {
	    
    }
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



void SelectionSolution::bubbleSort(int size)
{
    for (int i = 0; i < -1; i++)
    {
        // Last i elements are already in place  
        for (int j = 0; j < size - i - 1; j++)
        {
            if (_OperationArray[j] > _OperationArray[j + 1])
            {
                swapPositions(&_OperationArray[j], &_OperationArray[j + 1]);
            }
        }
    }
}














/*
 *
 * mport java.util.Arrays;

public class QuickSelect {

    public static void main(String[] args) {
        int[] arr = {4, 5, 1, 2, 3, 3,7,2,4,8,1};
        int k=3;
        System.out.println(kth_smallest_iteratively(arr,k,0,arr.length-1));
    }

    //returns median of 5 or less elements, uses in-place bubble sort/very well can use other in-place sort
    public static int med5(int[] arr, int start, int end){
        if(start==end)return arr[start];
        //sort elements
        for(int i=end;i>start;i--){
            for(int j=start+1;j<=end;j++){
                if(arr[j-1]>arr[j])
                    swap(arr,j,j-1);
            }
        }
        //return median
        return arr[start+((end-start+1)>>1)];
    }

    //get value for median of median
    public static int getMedianOfMedian(int[] arr, int start, int end){
        int n=end-start+1;
        if(n<=5) return med5(arr,start,end);//less than 5 elements
        int numOfGroups = n/5 + (n%5==0?0:1);

        //below medians array is allocated on each recurrsive call
        //can be minimized by passing it from client and reusing
        int[] medians = new int[numOfGroups];//one median for each subgroup

        for(int i=0;i<numOfGroups;i++){
            int groupStart=i*5;
            int groupEnd = Math.min(arr.length-1, i*5+5-1);//last group can have less than 5 elements
            medians[i]=med5(arr,groupStart,groupEnd);
        }
        return getMedianOfMedian(medians,0,medians.length-1);
    }

    //partition finds an pivot and put at its final place
    private static int partition_lamuto_stable(int[] arr, int start, int end){
        int pivot = getMedianOfMedian(arr,start,end);
        int higher=start;//starting index of higher elements than pivot
        int lower=start;//start index of lower elements than pivot
        int pivotIndex=start;//starting index of elemetns equal to pivot(dup pivot)
        int[] copy= new int[end-start+1];
        for(int i=start,k=0;i<=end;i++){
            if(arr[i]<=pivot)higher++;//count all smaller elements and pivot elements
            if(arr[i]<pivot)pivotIndex++;//count all smaller elements
            copy[k++]=arr[i];//create copy
        }

        for(int i=0;i<copy.length;i++){
            int index;
            if(copy[i]<pivot) index=lower++;
            else if(copy[i]==pivot) index=pivotIndex++;
            else index=higher++;
            arr[index]=copy[i];
        }

        return lower;//index of pivot
    }

    public static int kth_smallest_iteratively(int[] arr, int k, int start, int end){
        int pivotIndex=-1;
        while(true){
            pivotIndex=partition_lamuto_stable(arr, start,end);
            if(pivotIndex+1==k)return arr[pivotIndex];
            else if(pivotIndex+1<k) start=pivotIndex+1;
            else end= pivotIndex-1;
        }
    }

    private static void swap(int[] arr, int index1, int index2){
        int temp=arr[index1];
        arr[index1]=arr[index2];
        arr[index2]=temp;
    }
}

*/
 */