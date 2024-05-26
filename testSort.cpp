// Name:
#include "testSort.hpp"
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <cassert>
#include <iostream>
#include "Sort.hpp"
using namespace std;
using namespace std::chrono;
int randNum(int n) {
    return rand() % n;
}
void randArr(int* array, int n) {
    for(int i=0; i<n; i++) {
        array[i] = randNum(1000000);
    }
}
//int* randArr(int n) {
// int* arr = new int[n];
// for(int i=0; i<n; i++) {
// arr[i] = randNum(1000000);
// }
// return arr;
//}
bool validate(int *array, int n) {
    for(int i=0; i<n-1; i++) {
        if(array[i] > array[i+1]) {
            return false;
        }
    }
    return true;
}
void runTests(int insSizes[], int merSizes[], int n, int sorts) {
    int numTests = 10;
// int arr;
// int* toSort;
    string names[] = {"insertion sort", "merge sort", "merge-insertion sort"};
    int totalTime[] = {0,0,0};
    double totalComps[] = {0,0,0};
    double totalMoves[] = {0,0,0};
    Sort s;
    for (int i = 0; i < n; i++) { // for each size
        cout << names[0] << "\t\t";
        printf("n=%7d: ", insSizes[i]);
        for (int t = 0; t < numTests; t++) {
// generate tests
            int* const arrIns = new int[insSizes[i]];
            int* const toSortIns = new int[insSizes[i]];
            if(!arrIns || !toSortIns) {
                cout << "Error: out of memory. Exiting." << endl;
                exit(-1);
            }
            randArr(arrIns, insSizes[i]);
            copy(arrIns, arrIns + insSizes[i], toSortIns);
// insertion sort
            auto begin = high_resolution_clock::now();
            s.insertion_sort(toSortIns, insSizes[i]);
            auto dur = high_resolution_clock::now() - begin;
            totalTime[0] += (int) duration_cast<milliseconds>(dur).count();
            totalComps[0] += s.getComparisons();
            totalMoves[0] += s.getMoves();
            assert(validate(toSortIns, insSizes[i]));
            delete [] arrIns;
            delete [] toSortIns;
        } // numTests
// print test results
        cout << totalMoves[0] / numTests << " moves,\t";
        cout << totalComps[0] / numTests << " comparisons,\t";
        cout << totalTime[0] / numTests << "ms" << endl;
    } // size
// check if we're testing merge and merge-insertion sorts
    if(sorts>1) {
        for (int i = 0; i < n; i++) { // for each size
            int* const arrMer = new int[merSizes[i]];
            int* const toSortMer = new int[merSizes[i]];
            if(!arrMer || !toSortMer) {
                cout << "Error: out of memory. Exiting." << endl;
                exit(-1);
            }
            for (int t = 0; t < numTests; t++) {
// Merge Sort
                randArr(arrMer, merSizes[i]);
                copy(arrMer, arrMer + merSizes[i], toSortMer);
// merge sort
                auto begin = high_resolution_clock::now();
                s.merge_sort(toSortMer, merSizes[i]);
                auto dur = high_resolution_clock::now() - begin;
                totalTime[1] += (int)
                        duration_cast<milliseconds>(dur).count();
                totalComps[1] += s.getComparisons();
                totalMoves[1] += s.getMoves();
                assert(validate(toSortMer, merSizes[i]));
// merge-insertion sort
                if (sorts > 2) {
                    copy(arrMer, arrMer + merSizes[i], toSortMer);
// merge-insertion sort
                    begin = high_resolution_clock::now();
                    s.merge_insert_sort(toSortMer, merSizes[i]);
                    dur = high_resolution_clock::now() - begin;
                    totalTime[2] += (int)
                            duration_cast<milliseconds>(dur).count();
                    totalComps[2] += s.getComparisons();
                    totalMoves[2] += s.getMoves();
                    //assert(validate(toSortMer, merSizes[i]));
                }
            } // end test loop
            for (int si = 1; si < sorts; si++) {
                cout << names[si] << "\t\t";
                printf("n=%7d: ", merSizes[i]);
                cout << totalMoves[si] / numTests << " moves,\t";
                cout << totalComps[si] / numTests << " comparisons,\t";
                cout << totalTime[si] / numTests << "ms" << endl;
            }
            delete [] arrMer;
            delete [] toSortMer;
        } // end size loop
    } // end check if running merge sort
} // end runTests
