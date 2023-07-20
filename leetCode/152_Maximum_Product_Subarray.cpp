#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
    int maxProd = INT_MIN, minInc = 1, maxInc = 1;
    for (auto n : nums)
    {
        int t1 = minInc * n;
        int t2 = maxInc * n;
        maxInc = max(n, max(t1, t2));
        minInc = min(n, min(t1, t2));
        maxProd = max(maxInc, maxProd);
    }
    return maxProd;
}
int main()
{
    int n;
    cout << "Enter size of array\n";
    cin >> n;
    vector<int> v;
    cout << "Enter element\n";
    while(n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << maxProduct(v);
    return 0;
}