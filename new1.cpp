#include<bits/stdc++.h>
using namespace std;

static bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    vector<int> v1(4);
    v1 = {10,2,4,3};
    sort(v1.begin(),v1.end(),cmp);
    for(auto it:v1) cout << it << " ";
    return 0;
}