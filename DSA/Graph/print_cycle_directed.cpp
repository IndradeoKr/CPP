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
#define VV(x) vector<vector<x>>
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fd(i, a, n) for (int i = a; i >= n; i--)
#define F first
#define S second
/**********************************************************/
const int INF = 1e17;
const int NINF = -INF;
/**********************************************************/
 
bool dfs(int node, VV(int) & adj, V(int) & vis, V(int) & pathVis, V(int) & res)
{
    vis[node] = pathVis[node] = 1;
    res.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis, res))
                return true;
        }
        else if (pathVis[it])
        {
            res.push_back(it);
            return true;
        }
    }
    pathVis[node] = 0;
    res.pop_back();
    return false;
}
 
signed main()
{
    int n, m;
    cin >> n >> m;
 
    VV(int) adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
 
    V(int) vis(n + 1, 0), pathVis(n + 1, 0), res,ans;
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        if(dfs(i, adj, vis, pathVis, res))
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        int size = res.size()-1;
        int t = res[size];
        ans.push_back(t);
        for(int i = size-1; i >= 0; i--)
        {
            if(res[i] == t)
            {
                ans.push_back(res[i]);
                break;
            }
            else ans.push_back(res[i]);
        }
        reverse(all(ans));
        cout << ans.size() << endl;
        for (auto it:ans)
            cout << it << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE\n";
}