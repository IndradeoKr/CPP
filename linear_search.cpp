#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int *arr, int size, int key)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    int key;
    int ans;
    int *arr = NULL;
    cout << "Input size of array" << endl;
    cin >> n;
    arr = new int[n];
    cout << "Enter the elements of array" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter number to find" << endl;
    cin >> key;

    cout << LinearSearch(arr, n, key) << endl;
    return 0;
}