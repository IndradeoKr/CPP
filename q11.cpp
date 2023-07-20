#include <iostream>
using namespace std;


void reversed(int num)
{
    int a, b, c = 0;
    while (num != 0)
    {
        a = num % 10;
        num  = num / 10;
        b = a;
        c = c * 10 + b;
    }
    cout << "Reversed no. = " << c << endl;
}


int main ()
{
    int n;
    
    cout << "Enter a number" << endl;
    cin >> n;
    cout << "N = " << n << endl;
    reversed(n);
}