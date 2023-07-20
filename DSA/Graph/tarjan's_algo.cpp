#include<bits/stdc++.h>
using namespace std;


class Solution {
    int time = 1;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0), tin(n), low(n);
        vector<vector<int>> res;
        dfs(0,adj,vis,tin,low,res,-1);
        return res;
    }

    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &tin, vector<int> &low,vector<vector<int>> &res, int parent)
    {
        vis[i] = 1;
        tin[i] = low[i] = time++;
        
        for(auto it:adj[i])
        {
            if(it == parent) continue;
            if(!vis[it])
            {
                dfs(it,adj,vis,tin,low,res,i);
                low[i] = min(low[it],low[i]);
                if(low[it] > tin[i])
                {
                    res.push_back({i,it});
                }
            }
            else
            {
                low[i] = min(low[it],low[i]);
            }
        }
    }
};

int main()
{

}
