// bubble sort
int bubbleSort(int arr[], int size, int& numAssignments)
{
    int numComparisons = 0;// to store number of comparisons.
    numAssignments = 0;//to store number of assignments.
    bool swapped = true;// this is used to check wheather the swappe happened or not.
    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {
            numComparisons++;//calculating comparisons.
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                numAssignments += 3;//calculating assignments.
                swapped = true;
            }
        }
    }
    return numComparisons;
}

// selection sort
int selectionSort(int arr[], int size, int& numAssignments)
{
    int compares = 0;// to store number of comparisons.
    numAssignments = 0;//to store number of assignments.
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            compares++;//calculating comparisons.
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            numAssignments += 3; // calculating assignments.
        }
    }
    return compares;
}

//insertion sort
int insertionSort(int arr[], int size, int& numAssignments)
{
    int compares = 0;// to store number of comparisons.
    numAssignments = 0;//to store number of assignments.
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            compares++;//calculating comparisons.
            arr[j + 1] = arr[j];
            j--;
            numAssignments++;//calculating assignments.
        }
        arr[j + 1] = key;
        numAssignments++;//calculating assignments.
    }
    return compares;
}
