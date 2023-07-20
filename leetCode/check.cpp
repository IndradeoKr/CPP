#include <bits/stdc++.h>
using namespace std;
vector<int> answerQueries(vector<int> &v, vector<int> &q)
{
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
        v[i] += v[i - 1];
    // vector<int> ans;
    // for (int x : q)
    // {
    //     int idx = upper_bound(v.begin(), v.end(), x) - v.begin();
    //     ans.push_back(idx);
    // }
    return v;
}
int main()
{
    vector<int> v = {1,3,6,9};
    // auto it = upper_bound(v.begin(), v.end(), 6) - v.begin();
    // cout << it;
    vector<int> q = {3,10,21};
    vector<int> ans = answerQueries(v,q);
    for(auto& i:ans)
    {
        cout << i << " ";
    }
    return 0;
}