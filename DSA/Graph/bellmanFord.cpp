#include <bits/stdc++.h>
using namespace std;


/*macro function*/
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
    int n,m;
    cin >> n >> m;

    vector<tuple<int,int,int>> adj;
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj.push_back({a,b,-c});
    }

    vector<int> dis(n+1,INF);
    dis[1] = 0;
    for(int i = 0; i < n; i++)
    {
        for(auto it:adj)
        {
            int u,v,w;
            tie(u,v,w) = it;

            if(dis[u] == INF) continue;
            dis[v] = min(dis[v],dis[u]+w);
            // dis[v] = max(dis[v],NINF);
        }
    }

    /*
    To check negative cycle.
    if there is negative cycle than every node that gets affected by cycle will be
    replaced by NINF
    */
   
    for(int i = 0; i < n; i++)
    {
        for(auto it:adj)
        {
            int u,v,w;
            tie(u,v,w) = it;

            if(dis[u] == INF) continue;
            // dis[v] = max(dis[v],NINF);
            if(dis[v] > dis[u]+w)
            {
                dis[v] = NINF;
            }
        }
    }

    if(dis[n] == NINF) cout << -1 << endl;
    else cout << -dis[n] << endl;
}