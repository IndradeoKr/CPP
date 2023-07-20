#include <bits/stdc++.h>
using namespace std;
#include "template_2.cpp"
int main()
{
    Pair<Pair<int, int>, int> p1;
    Pair<int, int> p4;
    p4.setX(10);
    p4.setY(30);
    p1.setX(p4);
    p1.setY(50);
    cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;
    return 0;
}