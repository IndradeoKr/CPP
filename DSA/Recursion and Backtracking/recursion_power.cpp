#include <bits/stdc++.h>
using namespace std;

int Power(int base, int power)
{
    if(power != 0)
    {
        return (base*Power(base, power-1));
    }
    else
    return 1;
}
int main()
{
    int base, power;
    cout << "Enter base number" << endl;
    cin >> base;
    cout << "Enter power number" << endl;
    cin >> power;
    cout << "Your power is " <<Power(base, power) << endl;

    return 0;
}