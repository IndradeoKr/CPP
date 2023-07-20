#include <bits/stdc++.h>
using namespace std;

typedef vector<int> a;

int main()
{
    a b;
    for(int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    for(int i = 0; i < 5; i++)
    {
        cout << b[i];
    }
    return 0;
}