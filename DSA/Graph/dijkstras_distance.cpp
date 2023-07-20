#include<bits/stdc++.h>
using namespace std;

/*macro function*/
#define ll long long int
#define pb push_back
#define vi vector<ll>
#define fi(a,n) for(ll i = a; i < n; i++)
#define fd(a,n) for(ll i = a; i >= 0; i--)
#define F first
#define S second
/**********************************************************/

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<pair<ll,ll>> adj[n+1];

	for(int i = 0; i < m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}

	vector<ll> dis(n+1,LLONG_MAX),vis(n+1,0);
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push({0,1});
	dis[1] = 0;

	while(!pq.empty())
	{
		ll node = pq.top().S;
		ll distance = pq.top().F;
		pq.pop();
		// if(vis[node]) continue;
		vis[node] = 1;
		for(auto it:adj[node])
		{
			if(!vis[it.F] && dis[it.F] > (ll)it.S+distance)
			{
				dis[it.F] = (ll)it.S+distance;
				pq.push({(ll)it.S+distance,it.F});
			}
		}
	}

	for(int i = 1; i <= n; i++) cout << dis[i] << " ";
	cout << endl;
}