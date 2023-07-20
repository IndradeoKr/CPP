#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i = 10;
    int j = 21;
    int const * p = &i; // p is pointing to a constant integer.This is ment by p is constant. p can be change but *p cannot be changed.
    p = &j; // This is ture because *p is not constant.

    int * const p2 = &i; // This mean p2 is a constant pointer. So p2 cannot be changed but *p can be changed.
    (*p2)++; // This is true.
    //p2 = &j; //This is wrong because p2 is constant.

    int const * const p3 = &i; // This is mean p2 is constant pointer pointing to a constant integer.Here both p3 as well as *p3 cannot be changed.
    //p3 = &j; // wrong
    //(*p3)++; //wrong
    return 0;
}