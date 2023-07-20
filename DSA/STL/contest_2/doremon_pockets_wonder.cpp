#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x;
    cout << "Number of gadgets\n";
    cin >> n;
    multiset<int> gadgets;
    cout << "Id of gadgets\n";
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        gadgets.insert(x);
    }
    cout << "Enter number high priority gadgets\n";
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        int count_x = gadgets.count(x);
        while(count_x--)
        {
            cout << x << " ";
        }
        gadgets.erase(x);
    }
    for(auto e : gadgets)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}