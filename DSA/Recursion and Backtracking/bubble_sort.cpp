#include <bits/stdc++.h>
using namespace std;

int *bubble_sort(int *arr, int size, int j)
{
    if (size == 1)
        return arr;

    if (j == size-1)
        return arr;

    if (arr[j] >= arr[j + 1])
        swap(arr[j], arr[j + 1]);

    bubble_sort(arr, size, j + 1);

    bubble_sort(arr, size - 1, j);

    return arr;
}

int main()
{
    int n;

    cout << "Enter the size of array" << endl;
    cin >> n;

    int *arr = new int[n];

    cout << "Enter arr of size " << n << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(arr, n, 0);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}