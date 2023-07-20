#include <bits/stdc++.h>
using namespace std;
int main()
{
    int *p = new int; // New is used to use heap storage.
    delete p;
    p = new int;
    delete p; // simple deletion method.
    p = new int[50];
    delete[] p; // array deletion method.
    return 0;
}