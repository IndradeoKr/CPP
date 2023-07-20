#include <bits/stdc++.h>
using namespace std;
void tower(int n, char sour, char des, char aux)
{
    //base case
    if (n == 0)
        return;

//first step n-1 dicks moves from sour to aux using des.
    tower(n - 1, sour, aux, des);

    cout << "Move disk " << n << " from " << sour << " to " << des << endl;
//second step n-1 dicks moves from aux to des using sour.
    tower(n - 1, aux, des, sour);
    
}

int main()
{
    int n;

    cout << "Enter a number" << endl;
    cin >> n;

    tower(n, 'A', 'C', 'B');

    return 0;
}