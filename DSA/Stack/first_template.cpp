#include <bits/stdc++.h>
using namespace std;
#include "template.cpp"

int main()
{
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(10.34);
    p2.setY(20.33);
    cout << p2.getX() << " " << p2.getY() << endl;
    return 0;
}