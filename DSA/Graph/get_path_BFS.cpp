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
    queue<int> q;
    q.push(v1);
    vector<int> v;
    bool flag = false;
    visited[v1] = true;
    while (q.size() != 0)
    {
        int front = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (edge[front][i] == 1)
            {
                if(!visited[i]) v.push_back(front);
                if (front == v2)
                {
                    flag = true;
                    v.push_back(front);
                    return v;
                }
                if (visited[i])
                    continue;
                visited[i] = true;
                q.push(i);
                break;
            }
        }
    }
    if(!flag) v.clear();
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
    for (int i = v.size()-1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    return 0;
}