#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    int s1 = p1.second.first + p1.second.second;
    int s2 = p2.second.first + p2.second.second;
    if(s1 != s2) return s1 < s2;
    return p1.second.first < p2.second.first;
}

int main()
{
    int n;
    cout << "Enter number of pairs\n";
    cin >> n;
    vector<pair<int,pair<int,int>>> v(n);// first int contain index and others contain value.
    for(int i = 0; i < n; i++)
    {
        v[i].first = i;
        cin >> v[i].second.first >> v[i].second.second;
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> ans(n);
    for(int i = 0; i < v.size(); i++)
    {
        ans[v[i].first] = i;//v is sorted and i denotes the number of previous elements.
    }
    for(auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << "\n";
    return 0;
}