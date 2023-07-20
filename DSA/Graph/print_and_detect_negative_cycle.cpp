#include <bits/stdc++.h>
using namespace std;

/*macro function*/
#define all(x) x.begin(), x.end()
#define int long long int
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fd(i, a, n) for (int i = a; i >= n; i--)
#define F first
#define S second
/**********************************************************/
const int INF = 1e17;
const int NINF = -INF;
/**********************************************************/



signed main()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({a,b, c});
    }

    vector<int> dis(n+1,INF), path(n+1,-1);
    int x = -1;
    for(int i = 0; i < n; i++)
    {
        x = -1;
        for(auto it:adj)
        {
            int u,v,d;
            tie(u,v,d) = it;
            if(dis[u]+d < dis[v])
            {
                dis[v] = dis[u] + d;
                path[v] = u;
                x = v;
            }
        }
    }

    if(x == -1) cout << "NO\n";
    else
    {   
        for (int i = 0; i < n; ++i)
        {
            x = path[x];
            cout << x << endl;
        }

        vector<int> cycle;

        for (int v = x;;v = path[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        cout << "YES\n";
        reverse(all(cycle));
        for(auto it:cycle) cout << it << " ";
        cout << endl;
    }
}