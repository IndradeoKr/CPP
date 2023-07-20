#include <bits/stdc++.h>
using namespace std;

int tiling(int n)
{
    if(n < 1)
        return 0;
    if(n < 4)
        return 1;
    if(n == 4)
        return 2;

    return tiling(n-1) + tiling(n-4);
}

int main()
{
    int n;

    cout << "Enter the no. of tiles" << endl;
    cin >> n;

    cout << tiling(n) << endl;
    return 0;
}