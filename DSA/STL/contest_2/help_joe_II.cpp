#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long a[N];
int main()
{
    int n, m;
    cout << "Enter size of array\n";
    cin >> n;
    cout << "Enter modulus number\n";
    cin >> m;
    cout << "Enter elements of array\n";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        a[i] %= m;
    }
    sort(a,a+n);
    int q;
    cout << "Enter number of queries\n";
    cin >> q;
    while(q--)
    {
        long long x;
        cout << "Enter a constant number\n";
        cin >> x;
        x %= m;
        long long *ptr = upper_bound(a,a+n,m-x-1);
        if(ptr != a)
        {
            ptr--;
        }
        cout << max((a[n-1] + x)%m, (*ptr + x)%m) << endl;
    }
    return 0;
} 