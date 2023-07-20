#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int num;
    cout << "Enter number to find" << endl;
    cin >> num;
    int ptr = lower_bound(a,a+n,num) - a;//if not present than it find next element which is greater.
    // int *ptr = upper_bound(a,a+n,num);//it return next greater element which we have to find
    // if(ptr == (a+n))
    // {
    //     cout << "Not found" << endl;
    //     return 0;
    // }
    // cout << (*ptr) << endl;
    cout << a[ptr-1];
    return 0;
}