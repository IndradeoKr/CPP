#include <bits/stdc++.h>
using namespace std;

bool cpm(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if(a.first.first == b.first.first)
    {
        return a.second > b.second;
    }
    if(a.first.second == b.first.second)
    {
        return a.second > b.second;
    }
    return a.first.second < b.first.second;
}

int combination(int a)
    {
        if(a == 1 || a == 0) return 1;
        return a*combination(a-1);
    }

int numEquivDominoPairs(vector<vector<int>>& d) {
        map<vector<int>,int> sv;
        for(int i = 0; i < d.size(); i++)
        {
            sort(d[i].begin(), d[i].end());
            sv[d[i]]++;
        }
        int sum = 0;
        for(auto &it : sv)
        {
            if(it.second > 1)
            {
                int n = it.second;
                int comb = combination(n) / (2*(combination(n-2)));
                sum += comb;
            }
        }
        return sum;
    }

int main()
{
    vector<int> startTime = {1,2,3,3}, endTime = {3,4,5,6}, profit = {50,10,40,70};
    vector<pair<pair<int, int>, int>> v;
    sort(endTime.begin(),endTime.end());
    for(int i = 0; i < startTime.size(); i++)
    {
        pair<pair<int, int>, int> p;
        p.first.first = startTime[i];
        p.first.second = endTime[i];
        p.second = profit[i];
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cpm);
    int sum = v[0].second;
    int end = v[0].first.second;
    for(int i = 0 ; i < startTime.size(); i++)
    {
        if(end == v[i].first.first)
        {
            sum += v[i].second;
            end = v[i].first.second;
        }
    }
    cout << sum;
    return 0;
}