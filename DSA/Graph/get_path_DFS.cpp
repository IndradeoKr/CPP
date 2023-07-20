#include <bits/stdc++.h>
using namespace std;

void createGraph(int **edge, int e)
{
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edge[f][s] = 1;
        edge[s][f] = 1;
    }
}

vector<int> get_path(int **edge, int v1, int v2, int n, bool *visited)
{
    static vector<int> v;
    static bool flag = false;
    visited[v1] = true;
    for (int i = 0; i < n; i++)
    {
        if (edge[v1][i] == 1)
        {
            if (v1 == v2)
            {
                v.push_back(v1);
                flag = true;
                return v;
            }
            if (visited[i])
                continue;
            visited[i] = true;
            get_path(edge, i, v2, n, visited);
            if(flag) v.push_back(v1);
            else v.clear();
            break;
        }
    }
    return v;
}

int main()
{
    int n, e;
    vector<int> v;
    cout << "Enter of vertex and edge\n";
    cin >> n >> e;
    int **edge = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
        }
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    createGraph(edge, e);
    int v1, v2;
    cin >> v1 >> v2;
    v = get_path(edge, v1, v2, n, visited);
    for(auto &it : v)
    {
        cout << it << " ";
    }
    return 0;
}