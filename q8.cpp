#include <iostream>
using namespace std;
int main()
{
    float distance;
    int cAse;
    cout << "Enter the distance in KMs between two city" << endl;
    cin >> distance;
    cout << "choose any one option" << endl
         << "1. KMs to Meter" << endl
         << "2. KMs to Feet" << endl
         << "3. KMs to Inches" << endl
         << "4. KMs to Centimeter" << endl;
    cin >> cAse;
    switch (cAse)
    {
    case 1:
        cout << "KMs to Meter is " << distance * 1000;
        break;
    case 2:
        cout << "KMs to Feet is " << distance * 3280.8399;
        break;
    case 3:
        cout << "KMs to Inches is " << distance * 39370.0787;
        break; 
    case 4:
        cout << "KMs to Centimeter is " << distance * 100000;
        break;       

    default:
        cout << "!!! Choose valide option !!!" << endl;
        break;
    }
    return 0;
}