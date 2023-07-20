#include<bits/stdc++.h>
using namespace std;

/*macro function*/
#define ll long long



/*constraint*/
const int N = 1e5, M = 2*1e5;


/*viables*/
int n,m,till = -1;
vector<int> adj[N+1];
vector<int> res,vis(N+1,0); 



/*function*/
bool dfs(int start, int parent)
{
	vis[start] = 1;
	res.push_back(start);

	for(auto it:adj[start])
	{
		if(!vis[it])
		{
			if(dfs(it,start)) return true;
		}
		else if(parent != it)
		{
			till = it;
			return true;
		}
	}
	res.pop_back();
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	
	
	for(int i = 0; i < m; i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			if(dfs(i,-1))
			{
				// cout << res.size() << endl;
				vector<int> ans;
				bool flag = false;
				for(auto it:res)
				{
					if(it == till) flag = true;
					if(flag) ans.push_back(it);
				}

				cout << ans.size()+1 << endl;
				for(auto it:ans)
				{
					cout << it << " ";
				}
				cout << till << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}