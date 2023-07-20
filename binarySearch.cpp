#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int *arr, int size, int key)
{
    int s = 0, e = size;
    while(s <= e)
    {
        int mid = (s+e)/2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int main()
{
    int n;
    int key;
    int *arr;
    cout << "Input size of array" << endl;
    cin >> n;

    arr = new int[n];
    cout << "Input elements of array in increasing order" << endl;
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the number to find" << endl;
    cin >> key;

    cout << BinarySearch(arr, n, key) << endl;

    return 0;
}