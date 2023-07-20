#include<bits/stdc++.h>
using namespace std;

//dfs.........................
class Solution {
    bool cycle(vector<int> adj[], int vis[], int src, int parent = -1)
    {
        vis[src] = 1;
        for(auto it:adj[src])
        {
            if(!vis[it])
            {
                if(cycle(adj,vis,it,src)) return true;
            }
            else if(parent != it) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(cycle(adj,vis,i)) return true;
            }
        }
        return false;
    }
};

//bfs..............................
class Solution {
    bool cycle(vector<int> adj[], vector<int> &vis, int src)
    {
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = 1;
        while(!q.empty())
        {
            auto i = q.front();
            q.pop();
            int cur = i.first;
            int parent = i.second;
            
            for(auto it:adj[cur])
            {
                if(parent != it)
                {
                    if(!vis[it])
                    {
                        q.push({it,cur});
                        vis[it] = 1;
                    }
                    else return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(cycle(adj,vis,i)) return true;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}
