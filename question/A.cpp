#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
/* Template */
template<class T>  using indexed_set = tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;
/**********************************************************/
 
/*macro function*/
#define all(x) x.begin(), x.end()
#define int long long int
#define PQ(x) priority_queue<x, vector<x>, greater<x>>
#define tiii tuple<int, int, int>
#define tiic tuple<int, int, char>
#define tici tuple<int, char, int>
#define tcii tuple<char, int, int>
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pb push_back
#define V(x) vector<x>
#define vv(x) vector<vector<x>>
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fd(i, a, n) for (int i = a; i >= n; i--)
#define F first
#define S second
/**********************************************************/
const int INF = 1e17;
const int NINF = -INF;
const int N = 1e8;
const int mod = 1e9+7;
/**********************************************************/

class Solution{
    int dp[1001001];
    int n;
public:
    void solve(){
        cin >> n;
        memset(dp,-1,sizeof(dp));

        cout << rec(1) << endl;
    }

    int rec(int level){
        if(level == n) return 1;
        if(dp[level] != -1) return dp[level];

        int ans = 0;
        for(int i = 1; i <= 3; i++){
            if(level+i <= n) (ans += rec(level+i)) %= mod;
        }

        return dp[level] = ans%mod;
    }
};
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
        
    int t = 1;
    // cin >> t;
    while(t--){
        Solution s;
        s.solve();
    }
}
