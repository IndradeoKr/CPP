#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {2, 3, 5, 6, 7};
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    for(auto value : v)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}