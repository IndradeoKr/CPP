#include<bits/stdc++.h>
using namespace std;


//bfs.............................................................................
class Solution {
    bool bfs(vector<int>adj[], vector<int> &vis, vector<int> &col, int i)
    {
        queue<pair<int,int>> q;
        q.push({i,0});
        vis[i] = 1;
        col[i] = 0;
        
        while(!q.empty())
        {
            int node = q.front().first;
        	int color = q.front().second;
        	q.pop();
        	
        	for(auto it:adj[node])
        	{
        	    if(!vis[it])
        	    {
        	        vis[it] = 1;
        	        col[it] = (color+1)%2;
        	        q.push({it,(color+1)%2});
        	    }
        	    else if(color == col[it]) return false;
        	}
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V,0), col(V,-1);
	    for(int i = 0; i < V; i++)
	    {
	        if(!vis[i])
	        {
        	    if(!bfs(adj,vis,col,i)) return false;
	        }
	    }
	    return true;
	}

};


//dfs..............................................................................
class Solution {
    bool dfs(vector<int>adj[], vector<int> &vis, vector<int> &col, int i, int c)
    {
        vis[i] = 1;
        col[i] = c;
        
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(adj,vis,col,it,(c+1)%2)) return true;
            }
            else if(col[it] == c) return true;
        }
        return false;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V,0), col(V,-1);
	    for(int i = 0; i < V; i++)
	    {
	        if(!vis[i])
	        {
        	    if(dfs(adj,vis,col,i,0)) return false;
	        }
	    }
	    return true;
	}

};

int main()
{

    return 0;
}