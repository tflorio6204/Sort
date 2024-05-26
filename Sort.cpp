//
// Created by Leighanne on 11/2/2023.
//

#include "Sort.hpp"
#include <iostream>
using namespace std;

Sort::Sort() {
	comparisons = 0;
	moves = 0;
}

void Sort::insertion_sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int k = i;
        while(k > 0 && array[k-1] > array[k])
        {
            moves++;
            comparisons++;
            swap(array[k - 1], array[k]);
            k--;
        }
    }
}

void Sort::merge_sort(int *array, int size)
{
    merge_sort(array, 0, size-1);
}

void Sort::merge_insert_sort(int *array, int size)
{
    merge_insert_sort(array, 0, size - 1);
}

void Sort::merge_insert_sort(int *array, int start, int end)
{
    int subarraySize = 100;
    if ((end - start) < subarraySize)
    {
        comparisons++;
        insertion_sort(array, (end - start));
        return;
    }
    int midValue = start + (end - start)/2;
    merge_insert_sort(array, start, midValue);
    merge_insert_sort(array, midValue + 1, end);
    merge(array, start, midValue, end);
}

void Sort::merge_sort(int *array, int start, int end)
{
    if(start >= end)
    {
        comparisons++;
        return;
    }
    int midValue = start + (end - start)/2;
    merge_sort(array, start, midValue);
    merge_sort(array, midValue + 1, end);
    merge(array, start, midValue, end);
}

void Sort::merge(int *array, int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    int *leftPortion = new int[leftSize];
    int *rightPortion = new int[rightSize];

    for(int i = 0; i < leftSize; i++)
    {
        comparisons++;
        moves++;
        leftPortion[i] = array[start + i];
    }
    for(int j = 0; j < rightSize; j++)
    {
        comparisons++;
        moves++;
        rightPortion[j] = array[mid + 1 + j];
    }

    int leftIndex = 0; // left portion index
    int rightIndex = 0; // right portion index
    int arrayIndex = start;

    while(leftIndex < leftSize && rightIndex < rightSize)
    {
        comparisons += 3;
        if(leftPortion[leftIndex] <= rightPortion[rightIndex])
        {
            moves++;
            array[arrayIndex] = leftPortion[leftIndex];
            leftIndex++;
        }
        else
        {
            moves++;
            array[arrayIndex] = rightPortion[rightIndex];
            rightIndex++;
        }
        arrayIndex++;
    }
    while(leftIndex < leftSize)
    {
        comparisons++;
        moves++;
        array[arrayIndex] = leftPortion[leftIndex];
        leftIndex++;
        arrayIndex++;
    }
    while(rightIndex < rightSize)
    {
        comparisons++;
        moves++;
        array[arrayIndex] = rightPortion[rightIndex];
        rightIndex++;
        arrayIndex++;
    }
    delete[] leftPortion;
    delete[] rightPortion;
}

int Sort::getComparisons() {
	return comparisons;
}

int Sort::getMoves() {
	return moves;
}

void Sort::swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}
