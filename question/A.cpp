#include <bits/stdc++.h>
using namespace std;
 
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
/**********************************************************/

int dfs(int node, vv(int)&adj, V(int) &dis)
{
    if(dis[node] != -1) return dis[node];
    int sum = 0;
    for(auto it:adj[node])
    {
        sum = max(sum,dfs(it,adj,dis));
    }
    return dis[node] = 1+sum;
}

signed main()
{
    int n,m;
    cin >> n >> m;
    vv(int) adj(n+1);
    fi(i,0,m)
    {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    V(int) dis(n+1,-1);
    int ans = 0;
    fi(i,1,n+1)
    {
        ans = max(ans,dfs(i,adj,dis));
    }
    cout << ans-1 << endl;
}