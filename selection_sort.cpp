#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int key;
    int *arr;
    cout << "Input size of array" << endl;
    cin >> n;

    arr = new int[n];

    cout << "Enter elements of array" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[i])
            {
                // int temp = arr[j];
                // arr[j] = arr[i];
                // arr[i] = temp;
                swap(arr[i], arr[j]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}