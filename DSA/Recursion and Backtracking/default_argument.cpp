#include <bits/stdc++.h>
using namespace std;


int sum (int a[], int size, int si = 0)// always give default value to right most variable.
{
    int ans = 0;
    for(int i = 0; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}


// int sum2(int a, int b, int c, int d = 0)
// {
//     return a + b + c + d;
// }


int main()
{
    int a[4];
    for(int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    cout << sum(a, 4);
    return 0;
}
