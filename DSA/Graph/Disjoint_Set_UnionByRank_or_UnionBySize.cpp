#include<bits/stdc++.h>
using namespace std;

class Disjoint
{
    vector<int> rank, parent, size;
    public:
    Disjoint(int n)
    {
        parent.resize(n+1);//n+1 -> for 1 based index
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i = 0; i < n+1; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_p(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = find_p(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = find_p(u);
        int ulp_v = find_p(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = find_p(u);
        int ulp_v = find_p(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    Disjoint ds(7);
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);

    // //checking if 3 and 7 have same parent or not.
    // if(ds.find_p(3) == ds.find_p(7)) cout << "Same\n";
    // else cout << "Not Same\n";

    // ds.unionByRank(3,7);

    // if(ds.find_p(3) == ds.find_p(7)) cout << "Same\n";
    // else cout << "Not Same\n";

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    //checking if 3 and 7 have same parent or not.
    if(ds.find_p(3) == ds.find_p(7)) cout << "Same\n";
    else cout << "Not Same\n";

    ds.unionBySize(3,7);

    if(ds.find_p(3) == ds.find_p(7)) cout << "Same\n";
    else cout << "Not Same\n";

    return 0;
}