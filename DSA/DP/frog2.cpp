#include<bits/stdc++.h>
using namespace std;
// recursion will give TLE
// so use top down approch.
int jump(int n, int arr[], int k, vector<int> &dp)
{
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int mnSteps = INT_MAX;
    int j = INT_MAX;
    for(int i = 1; i <= k; i++)
    {
        if(n-i >= 0) j = jump(n-i,arr,k,dp) +abs(arr[n] - arr[n-i]);
        mnSteps = min(mnSteps,j);
    }
    return mnSteps;
}

int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n,0);
   // cout << jump(n-1,arr,k,dp);
    for(int i = 1; i < n; i++)
    {
        int mnSteps = INT_MAX;
        for(int j = 1; j <= k; j++)
        {
            if(i-j >= 0)
            {
                int temp = dp[i-j] + abs(arr[i]-arr[i-j]);
                mnSteps = min(mnSteps,temp);
            } 
        }
        dp[i] = mnSteps;
    }
    cout << dp[n-1];
    return 0;
}
