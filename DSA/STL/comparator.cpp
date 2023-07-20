#include <bits/stdc++.h>
using namespace std;

class compare
{
    public:
    bool operator ()(const int &a, const int &b)
    {
        return a>b;
    }
};

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first != b.first)
    {
        return (a.first < b.first);
    }
   return (a.second > b.second);
}

int main()
{
    int n;
    cout << "Enter the size pf array\n";
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    //sort(a,a+n); //for array
    sort(a.begin(), a.end(),cmp);
    cout << "after sort" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }

    set<int, compare> st; // compare is used to store accordingly.
    st.insert(2);
    st.insert(1);
    st.insert(3);
    cout << "set:\n";
    for(auto it : st)
    {
        cout << it << " ";
    }
    return 0;
}