#include<bits/stdc++.h>
using namespace std;

//shortest path using topological short.....dfs......src node = 0;
class Solution {
    private:
    void dfs(vector<pair<int,int>> adj[], stack<int> &topo, int i,vector<int> &vis)
    {
        vis[i] = 1;
        
        for(auto it:adj[i])
        {
            if(!vis[it.first]) dfs(adj,topo,it.first,vis);
        }
        topo.push(i);
    }
    public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        
        for(int i = 0; i <M; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int> vis(N,0);
        stack<int> st;
        
        for(int i = 0 ; i < N; i++)
        {
            if(!vis[i]) dfs(adj,st,0,vis);
        }
        
        vector<int> dist(N,1e7);
        dist[0] = 0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto it:adj[node])
            {
                if(dist[node]+it.second < dist[it.first])
                {
                    dist[it.first] = dist[node]+it.second;
                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            if(dist[i] == 1e7) dist[i] = -1;
        }
        return dist;
    }
};

int main()
{
    return 0;
}