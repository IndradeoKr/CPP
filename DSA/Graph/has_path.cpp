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

void printDFS(int **edge, int n, int sv, bool* visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edge[sv][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edge, n, i, visited);
        }
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            printDFS(edges,n,i,visited);
        }
    }
    delete []visited;
}

bool hasPath(int** edge, int v1, int v2, int n, bool* visited)
{
    visited[v1] = true;
    for(int i = 0; i < n; i++)
    {
        if(i == v1) continue;
        if(edge[v1][i] == 1)
        {
            if(edge[i][v2] == 1) return true;
            if(visited[i]) continue;
            visited[i] = true;
            if(hasPath(edge, i, v2, n, visited)) return true;
        }
    }
    return false;
}

int main()
{
    int n, e;
    cout << "Enter number of vertex and edge\n";
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
    DFS(edge, n);
    int v1, v2;
    cout << "Enter two vertex two check has path or not\n";
    cin >> v1 >> v2;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    if(hasPath(edge,v1,v2,n,visited)) cout << "True\n";
    else cout << "False\n";
    for(int i = 0; i < n; i++)
    {
        delete [] edge[i];
    }
    delete [] edge;
    delete [] visited;
    return 0;
}