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

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(q.size() != 0)
    {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for(int i = 0; i < n; i++)
        {
            if(i == front) continue;
            if(edges[front][i])
            {
                if(visited[i]) continue;
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void BFS(int **edges, int n)
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
            printBFS(edges, n, i, visited);
        }
    }
    delete []visited;
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

int main()
{
    int n; // number of vertices
    int e; // number of edges
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

    for (int i = 0; i < e; i++)
    {
        int f; // fisrt vertex
        int s; // second vertex
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "BFS: ";
    BFS(edges,n);
    cout << endl;
    cout << "DFS: ";
    DFS(edges,n);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
        delete[] edges;
    }

    return 0;
}