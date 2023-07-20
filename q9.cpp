#include <iostream>
using namespace std;
int main()
{
    int angle1, angle2, angle3;
    cout << "Enter angles to identify the triangle" << endl;
    cin >> angle1 >> angle2 >> angle3;
    int sum = angle1 + angle2 + angle3;
    if (sum > 180)
    {
        cout << "Triangle is not valid" << endl;
    }
    else
    {
        if (angle1 == 90 || angle2 == 90 || angle3 == 90)
        {
            cout << "Right angled triangle" << endl;
        }
        else if (angle1 == angle2 && angle2 == angle3)
        {
            cout << "Equilateral triangle" << endl;
        }
        else if (angle1 == angle2 || angle2 == angle3 || angle1 == angle3)
        {
            cout << "Isoceles triangle" << endl;
        }
        else
        {
            cout << "Scalan triangle" << endl;
        }
    }

    return 0;
}