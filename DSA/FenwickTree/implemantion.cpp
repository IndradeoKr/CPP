#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/* 1-index based implemention */

const int N = 7;
ll fen[N+1];

void update(int i, int add)
{
    while(i <= N)
    {
        fen[i] += (ll)add;
        i += (i&(-i));
    }
}

ll sum(int i)
{
    ll s = 0;
    while(i > 0)
    {
        s += fen[i];
        i = i - (i&(-i));
    }
    return s;
}

ll range(int l, int r)
{
    return sum(r) - sum(l-1);
}

int main()
{
    memset(fen,0,sizeof(fen));
    for(int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        update(i,x);
    }
    
    cout << range(1,7);
    return 0;
}