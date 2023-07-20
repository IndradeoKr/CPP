#include<bits/stdc++.h>
using namespace std;

//topological sort.
//bfs...............................................................................
class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    for(int i = 0; i < V; i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++)
	    {
	        if(indegree[i] == 0) q.push(i);
	    }
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	        
	    }
	    return topo;
	}
};

//dfs........................................................................
class Solution
{
    private:
    void dfs(vector<int> adj[], vector<int> &vis, stack<int> &s, int i)
    {
        vis[i] = 1;
        for(auto it:adj[i])
        {
            if(!vis[it]) dfs(adj,vis,s,it);
        }
        s.push(i);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> s;
	    for(int i = 0; i < V; i++)
	    {
	        if(!vis[i]) dfs(adj,vis,s,i);
	    }
	    
	    vector<int> topo;
	    while(!s.empty())
	    {
	        topo.push_back(s.top());
	        s.pop();
	    }
	    return topo;
	}
};

//dfs with cycle detection.

class Solution {
private:
	bool dfs(vector<vector<int>>& g, vector<int> &v, vector<int> &pv, vector<int> &res, int i)
    {
        v[i] = pv[i] = 1;

        for(auto it:g[i])
        {
            if(!v[it])
            {
                if(dfs(g,v,pv,res,it)) return true;
            }
            else if(pv[it]) return true;
        }
        pv[i] = 0;
        res.push_back(i);
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> v(n,0), pv(n,0);
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            if(!v[i]) dfs(g,v,pv,res,i);
        }
        sort(res.begin(),res.end());
        return res;
    }
};

int main()
{

    return 0;
}