#include <bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for(int  i = 0; i  < n; i++)
    {
        if(i == sv) continue;
        if(edges[sv][i] == 1)
        {
            if(visited[i]) continue;
            printDFS(edges,n,i,visited);
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
        if(i > 0 && !visited[i])
        {
            cout << endl;
        }
        if(!visited[i])
        {
            printDFS(edges,n,i,visited);
        }
    }
    delete []visited;
}

void createGraph(int **egdes, int e)
{
    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f>> s;
        egdes[f][s] = 1;
        egdes[s][f] = 1;
    }
}

int main()
{
    int n, e;
    cout << "Enter number of vertices and edges\n";
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    createGraph(edges,e);
    DFS(edges, n);
    return 0;
}