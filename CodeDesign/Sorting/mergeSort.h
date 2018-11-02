#pragma once
#include <iostream>
#include <vector>

// merge
// This function accepts a range of elements to sort. Used as a part of the
// merge sort function to merge subsections of the array.
//
//   arr is the array being sorted by the merge operation
//   p is the first index to start merging and sorting from
//   q is the index between p and r
//   r is the last index to merge and sort through
//
//   indices p, q, r, are guaranteed to have these values: p ≤ q < r
//     p is less than or equal to q
//     q is less than r
void Merge(int * arr, size_t p, size_t q, size_t r)
{
	// leftEnd = q - p + 1
	int leftEnd = q - p + 1;
	// rightEnd = r - q
	int rightEnd = r - q;

	// create an array that is size: leftEnd
	int * leftArray = new int[leftEnd];
	// create an array that is size: rightEnd
	int * rightArray = new int[rightEnd];

	// copy left elements into leftArray
	for (size_t i = 0; i < leftEnd; i++)
	{
		leftArray[i] = arr[p + i];
	}
	// copy right elements into rightArray
	for (size_t i = 0; i < rightEnd; i++)
	{
		rightArray[i] = arr[q + i + 1];
	}

	// i = 0
	int i = 0;
	// j = 0
	int j = 0;

	// for all values from p to r = k
	for (size_t k = p; k <= r; k++)
	{
		// if (j >= rightEnd) OR
		//    (i < leftEnd AND leftArray[i] <= rightArray[j]) then
		if ((j >= rightEnd) || (i < leftEnd && leftArray[i] <= rightArray[j]))
		{
			// set A[k] to the value of leftArray[i]
			arr[k] = leftArray[i];
			// increase i by one
			i++;
		}
		// else
		else
		{
			// set A[k] = R[j]
			arr[k] = rightArray[j];
			// increase j by one
			j++;
		}
	}
	delete[] leftArray;
	delete[] rightArray;
}

// merge sort
//   arr is the array being sorted
//   p is the first index to start sorting from
//   r is the last index to start sorting from
void MergeSort(int * arr, size_t p, size_t r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}