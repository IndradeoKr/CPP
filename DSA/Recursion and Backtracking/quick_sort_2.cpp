#include <bits/stdc++.h>
using namespace std;

int partiton(int arr[], int start, int end)
{
	int count = start;
	for (int i = start; i <= end; i++)
	{
		if (arr[start] > arr[i])
			count++;
	}
	swap(arr[start], arr[count]);

	int i = start;
	int j = end;
	while (i <= count && j >= count)
	{
		if (arr[i] < arr[count])
			i++;
		if (arr[j] > arr[count])
			j--;
		if (arr[i] >= arr[count] && arr[j] <= arr[count])
		{
			swap(arr[i], arr[j]);
			i++, j--;
		}
	}

	return count;
}

void quick_sort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int p = partiton(arr, start, end);
	quick_sort(arr, start, p - 1);
	quick_sort(arr, p + 1, end);
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int size;

	cout << "Enter the size of array" << endl;
	cin >> size;

	int *arr = new int[size];

	cout << "Enter array of size " << size << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	quick_sort(arr, 0, size - 1);
	printArray(arr, size);
	return 0;
}