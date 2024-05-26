//
// Created by Leighanne on 11/2/2023.
//

#ifndef SORTINGMINIPROJ_SORT_HPP
#define SORTINGMINIPROJ_SORT_HPP


class Sort {
private:
	long comparisons;
	long moves;
public:


public:
	Sort();
	void insertion_sort(int* array, int size); // basic insertion sort
	void merge_sort(int* array, int size); // basic merge sort (if recursive, call the recursive version)
	void merge_insert_sort(int* array, int size);
    void merge_insert_sort(int *array, int start, int end);
    void merge_sort(int *array, int start, int end);
	void merge(int* array, int start, int mid, int end); //optional helper function
	int getComparisons();
	int getMoves();
	void swap(int& x, int& y); // helper function for swapping. Call using swap(a, b);
};


#endif //SORTINGMINIPROJ_SORT_HPP
