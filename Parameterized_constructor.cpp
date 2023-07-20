#include <bits/stdc++.h>
using namespace std;

class point
{
    int x1, y1, a, b, c, d;

public:
    point(int a1, int b1, int a2, int b2)
    {
        a = a1;
        b = b1;
        c = a2;
        d = b2;
        x1 = (a1 - b1) * (a1 - b1);
        y1 = (a2 - b2) * (a2 - b2);
    }

    void printnumber()
    {
        cout << "1st point = (" << a << ", " << b << ")" << endl;
        cout << "2nd point = (" << c << ", " << d << ")" << endl;
        float d = sqrt(x1 + y1);
        cout << "Distance between two points are " << d << endl;
    }
};
int main()
{
    int a, b, c, d;
    cout << "Enter 1st point" << endl;
    cin >> a >> b;
    cout << "Enter 2nd point" << endl;
    cin >> c >> d;
    point a1(a, b, c, d);
    a1.printnumber();
    return 0;
}