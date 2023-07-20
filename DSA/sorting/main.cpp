#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchSortAlgorithms.h"

using namespace std;

const int ARRAY_SIZE = 5000;

int main()
{
    int list1[ARRAY_SIZE], list2[ARRAY_SIZE], list3[ARRAY_SIZE];
    int numComparisons;//sort number of comprisons.
    int numAssignments;//sort number of assignments.

    // initialize arrays with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int randomValue = rand() % 10000;
        list1[i] = randomValue;
        list2[i] = randomValue;
        list3[i] = randomValue;
    }

    // bubble sort
    cout << "Bubble Sort:\n";
    numComparisons = bubbleSort(list1, ARRAY_SIZE, numAssignments);
    cout << "Comparisons: " << numComparisons << ", Assignments: " << numAssignments << endl;

    // selection sort
    cout << "\nSelection Sort:\n";
    numComparisons = selectionSort(list2, ARRAY_SIZE, numAssignments);
    cout << "Comparisons: " << numComparisons << ", Assignments: " << numAssignments << endl;

    // insertion sort
    cout << "\nInsertion Sort:\n";
    numComparisons = insertionSort(list3, ARRAY_SIZE, numAssignments);
    cout << "Comparisons: " << numComparisons << ", Assignments: " << numAssignments << endl;

    return 0;
}
