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

bool dfs(int node, vv(int) &adj, V(int) &res, V(int)&vis, V(int) &pv)
{
    vis[node] = pv[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,adj,res,vis,pv)) return true;
        }
        else if(pv[it]) return true;
    }
    pv[node] = 0;
    res.push_back(node);
    return false;
}

signed main()
{
    int n, m;
    cin >> n >> m;
 
    vv(int) adj(n + 1);
    V(int) id(n+1), res, vis(n+1,0), pv(n+1,0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        id[b]++;
    }
    for(int i = 0; i <= n; i++)
    {
        if(!vis[i])
        {
            if(dfs(i,adj,res,vis,pv))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(int i = n; i >= 1; i--) cout << res[i] << " ";
}