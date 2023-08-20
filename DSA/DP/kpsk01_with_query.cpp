#include<bits/stdc++.h>
using namespace std;

int rec(int level, int left, vector<int> &x,vector<vector<int>> &dp, int n){
    if(left < 0){
        return 0;
    }

    if(level == n){
        return left==0;
    }

    if(dp[level][left] != -1){
        return dp[level][left];
    }

    int ans = 0;
    if(rec(level+1,left,x,dp,n)){
        ans = 1;
    }
    else if(rec(level+1,left-x[level],x,dp,n)){
        ans = 1;
    }

    return dp[level][left] = ans;
            
}

void printset(int level,int left, vector<int>& x, vector<vector<int>> &dp ,int n){
	if(level == n){
        return;   
    }

    if(rec(level+1,left,x,dp,n)){
        printset(level+1,left,x,dp,n);
    }
    else if(rec(level+1,left-x[level],x,dp,n)){
        cout << x[level] << " ";
        printset(level+1,left-x[level],x,dp,n);
    }
}

void solve(){
    int n,t;
    cin >> n;
    vector<int> x;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        x.push_back(a);
    }

    vector<vector<int>> dp(n+1,vector<int>(t+1,-1));

    int q; cin >> q;
    while(q--){
        cin >> t;
        if(rec(0,t,x,dp,n)){
            printset(0,t,x,dp,n);
            cout << endl;
        }
        else{
            cout << "No Solution Possible" << endl;
        }
    }
}

int main(){
    int t = 1;

    while(t--){
        solve();
    }
    return 0;
}
