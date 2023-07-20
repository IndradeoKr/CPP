#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(const vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return b[0] > a[0];
        return b[1] > a[1];
    }
};

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    for (int i = 0; i < boxTypes.size(); i++)
    {
        pq.push(boxTypes[i]);
    }
    int sum = 0;
    while (truckSize != 0)
    {
        vector<int> temp = pq.top();
        pq.pop();
        if (temp[0] >= truckSize)
        {
            sum += truckSize * temp[1];
            break;
        }
        else
        {
            sum += temp[0] * temp[1];
            truckSize -= temp[0];
        }
    }
    return sum;
}

int main()
{
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push({1, 3});
    pq.push({2, 2});
    pq.push({7, 2});
    pq.push({3, 1});
    vector<vector<int>> v = {{1, 3}, {2, 2}, {3, 1}};
    cout << maximumUnits(v, 4);

    // while(!pq.empty())
    // {
    //     vector<int> p = pq.top();
    //     cout << pq.top()[0] << " " <<pq.top()[1] << endl;
    //     pq.pop();
    // }

    return 0;
}