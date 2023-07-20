#include <bits/stdc++.h>
using namespace std;

void printVec(vector <pair <int, int> > &v)
{
    cout << "Size: " << v.size() << endl;
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}

int main()
{
    //vector <pair <int, int> > v = {{1,2}, {2,3}, {3,4}, {4,5}};
    //printVec(v);
    vector <pair <int, int> > v;
    vector<vector<int>> s;
    int row  = 4;
    int col = 4;
    for(int i = 0; i < row; i++)
    {
        vector<int> temp;
        for(int j = 0; j < col; j++)
        {
            int n;
            cin >> n;
            temp.push_back(n);
        }
        s.push_back(temp);
    }
    int n;//size of vector.
    cout << "Input size" << endl;
    cin >> n;
    cout << "Input value in pair" << endl;
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    printVec(v);
    return 0;
}