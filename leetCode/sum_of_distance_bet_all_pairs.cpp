#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll sum(vector<int> &arr)
{
    ll ans = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        ans += i*(ll)arr[i] + (n-i-1)*(ll)arr[i];
    }
    return ans;
}

int main()
{
    vector<int> arr = {5,2,7,2,8,0,1,2};
    cout << sum(arr) << endl;
    return 0;
}