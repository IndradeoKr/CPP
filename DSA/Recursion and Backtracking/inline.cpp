#include <bits/stdc++.h>
using namespace std;


inline int max(int a, int b) // it is used for 1 line only because it depends on the compiler to do or not. for 1 line code its always compile.
{
    return ((a > b) ? a : b);
}


int main()
{
    int a, b;
    cin >> a >> b;
    int c = max(a, b);
    cout << c << endl;


    int x = 10, y = 20;
    int z = max(x, y);
    cout << z << endl;
    return 0;
}