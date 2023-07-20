#include <bits/stdc++.h>
using namespace std;

int tiling(int n)
{
    if(n == 0)
        return n;
    int co = tiling(n-1);
    cout << co << endl;
    return n;
    
}

int main()
{
    int n;

    cout << "Enter the no. of tiles" << endl;
    cin >> n;

    cout << "Method 1st : " <<tiling(n) << endl;
    //cout << "Method 2nd : " <<Tiling(n) << endl;
    return 0;
}