#include <iostream>
#include "SortMC.h"

using namespace std;


SortMC::~SortMC()
{

}
int* SortMC::bubbleSort(int a[], int length) {
	int outer, inner;
	for (outer = length - 1; outer > 0; outer--)
	{ // counting down
		for (inner = 0; inner < outer; inner++)
		{ // bubbling up
			if (a[inner] > a[inner + 1])
			{ // if out of order...swap
				int temp = a[inner];
				a[inner] = a[inner + 1];
				a[inner + 1] = temp;
			}
		}
	}
	return a;
}
int* SortMC::selectionSort(int a[], int length) {
	int outer, inner, min;
	for (outer = 0; outer < length - 1; outer++)
	{ // outer counts down
		min = outer;
		for (inner = outer + 1; inner < length; inner++)
		{
			if (a[inner] < a[min]) {
				min = inner;
			}
		}
		// a[min] is least among a[outer]..a[a.length - 1]
		int temp = a[outer];
		a[outer] = a[min];
		a[min] = temp;
	}
	return a;
}
int* SortMC::insertionSort(int a[], int length)
	{
		int i, j, tmp;
		for (i = 1; i < length; i++)
		{
			j = i;
			while (j > 0 && a[j - 1] > a[j])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				j--;
			} //end of while loop
		} //end of for loop
		return a;
	}
int* SortMC::shellSort(int a[], int length)
{
	int i, j, increment, temp;
	for (increment = length / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i<length; i++)
		{
			temp = a[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (temp < a[j - increment])
				{
					a[j] = a[j - increment];
				}
				else
				{
					break;
				}
			}
			a[j] = temp;
		}
	}
	return a;
}
void SortMC::mergeSort(int a[], int left, int middle, int right){
	// creates temp array and needed variables
	int temp[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int i, left_end, num_elements, tmp_pos;

	left_end = (middle - 1);
	tmp_pos = left;
	num_elements = (right - left + 1);

	while ((left <= left_end) && (middle <= right))
	{
		if (a[left] <= a[middle])
			temp[tmp_pos++] = a[left++];
		else
			temp[tmp_pos++] = a[middle++];
	}

	while (left <= left_end)
		temp[tmp_pos++] = a[left++];

	while (middle <= right)
		temp[tmp_pos++] = a[middle++];

	for (i = 0; i < num_elements; i++)
	{
		a[right] = temp[right];
		right--;
	}
}
void SortMC::mergeSort(int a[], int left, int right){

	if (right > left)
	{
		// Middle for splitting
		int mid = (right + left) / 2;

		//sorts left, recursivly
		mergeSort(a, left, mid);

		//sorts Right, recursivly
		mergeSort(a, (mid + 1), right);

		mergeSort(a, left, (mid + 1), right);
	}
}
void SortMC::quickSort(int a[], int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = partition(a, left, right);
		quickSort(a, left, middle - 1);
		quickSort(a, middle + 1, right);
	}
}
int SortMC::partition(int a[], int left, int right)
{
	int  index = left;
	int temp;
	int middle = a[left];

	for (int i = left + 1; i <= right; i++)
	{
		if (a[i] <= middle)
		{
			index++;
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
	temp = a[index];
	a[index] = a[left];
	a[left] = temp;

	return index;
}