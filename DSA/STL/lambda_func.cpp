#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> v = {{1, 3}, {2, 2}, {3, 1}};
    // auto sum = [](int x, int y){return x+y;};//lambda function.
    // cout << sum(2,3);
    sort(v.begin(), v.end(), [](vector<int> a, vector<int> b)
         { return (b[1] < a[1]); });
    for (auto i : v)
    {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}