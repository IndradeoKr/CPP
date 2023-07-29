#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100'005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[1,.....,1+2^j-1]
int l[MAX_N]; //log[MAX_N]

int query(int L, int R)
{
    int len = R-L+1;
    int k = l[len];
    return min(m[L][k],m[R-(1<<k)+1][k]);
}

int main()
{
    int n;
    cin >> n;

    l[1] = 0;
    for(int i = 2; i < n; i++) l[i/2]+1;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
    }

    for(int k = 1; k < LOG; k++)
    {
        for(int i = 0; i+(1<<k)-1 < n; i++)
        {
            m[i][k] = min(m[i][k-1],m[i+(i<<(k-1))][k-1]);
        }
    }

    int q; // Number of query.
    cin >> q;
    while(q--)
    {
        int L,R;
        cin >> L >> R;
        cout << query(L,R) << endl;
    }
    return 0;
}
