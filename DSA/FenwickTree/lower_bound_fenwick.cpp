#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/* 1-index based implemention */
/* for sum which is present in last index you have to modify this code */

const int N = 8;
ll fen[N+1] = {0};

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

ll lowerBounnd(int k)
{
    int cur = 0, ans = 0, preSum = 0;
    for(int i = log2(20); i >= 0; i--)
    {
        if(cur+(1<<i) <= N)
        {
            if(fen[cur+(1<<i)] + preSum < k)
            {
                cur = cur + (1<<i);
                preSum += fen[cur];
            }
        }
    }
    return (cur + 1);
}

int main()
{
    for(int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        update(i,x);
    }
    
    cout << range(1,7) << endl;
    cout << lowerBounnd(16) << endl;
    return 0;
}