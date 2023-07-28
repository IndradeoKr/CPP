#include<bits/stdc++.h>
using namespace std;

class TreeAncestor {
    vector<vector<int>> up;
public:
    TreeAncestor(int n, vector<int>& parent) {
        up = vector<vector<int>>(n, vector<int>(20));
        for(int v = 0; v < n; v++) up[v][0] = parent[v];
        
        for(int j = 1; j < 20; j++)
        {
            for(int v = 0; v < n; v++){
                if(up[v][j-1] == -1) up[v][j] = -1;
                else up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for(int j = 0; j < 20; j++) {
            if(1 & (k >> j)) {
                node = up[node][j];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};