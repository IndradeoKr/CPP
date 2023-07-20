#include<bits/stdc++.h>
using namespace std;

//dfs
class Solution {
public:
    bool dfs(int i, vector<int> &vis, vector<int> &pathvis, vector<vector<int>>& adj)
    {   
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathvis,adj)) return true;
            }
            else if(pathvis[it]) return true;
        }
        pathvis[i] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> vis(n,0), pathvis(n,0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < p.size() ; i++)
        {
            adj[p[i][0]].push_back(p[i][1]);
        }

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathvis,adj)) return false;
            }
        }
        return true;
    }
};

//bfs
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> indgree(n,0);
        vector<int> adj[n];
        for(int i = 0; i < p.size(); i++)
        {
            adj[p[i][0]].push_back(p[i][1]);
            indgree[p[i][1]]++;
        }
        int cnt = 0;
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indgree[i] == 0) q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            cnt++;
            q.pop();
            for(auto it:adj[node])
            {
                indgree[it]--;
                if(indgree[it] == 0) q.push(it);
            }
        }
        return cnt == n;
    }
};

int main()
{

    return 0;
}