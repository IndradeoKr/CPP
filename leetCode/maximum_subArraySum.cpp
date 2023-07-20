#include <bits/stdc++.h>
using namespace std;

int MaximumSubArraySum(vector<int> v)
{
    int best = 0, sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum = max(v[i],sum+v[i]);
        best = max(sum,best);
    }
    return best;
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
    cout << MaximumSubArraySum(v);
    return 0;
}