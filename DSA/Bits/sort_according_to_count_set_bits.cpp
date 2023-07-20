//sort in decreasing order
// note:- : For integers having same number of set bits in their binary representation, 
//sort according to their position in the original array i.e., a stable sort.

#include<bits/stdc++.h>
using namespace std;

static bool cmp(int a, int b)
{
    return __builtin_popcount(a) > __builtin_popcount(b);
}

int main()
{
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = 9;
    stable_sort(arr,arr+n,cmp);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}