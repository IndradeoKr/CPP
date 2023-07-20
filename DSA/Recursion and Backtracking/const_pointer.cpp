#include <bits/stdc++.h>
using namespace std;

void g(const int & a) 
{
//     a++; // This is wrong method.
}

void f(const int * p)
{
    // (*p)++; // This is wrong method.
}
int main()
{
    int const i = 10;
    int const * p =&i;
    int j = 12;
    int * p3 = &j;
    f(p3);
    g(j);

    int const * p2 = &j;
    cout << *p2 << endl;
    j++;
    cout << *p2 << endl;
    
    return 0;
}