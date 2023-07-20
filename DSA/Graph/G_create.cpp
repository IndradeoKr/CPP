#include <bits/stdc++.h>
using namespace std;

void print_DFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv) continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i]) continue;
            print_DFS(edges, n, i, visited);
        }
    }
}

void print_DFS_stack(int **edges, int n, int sv, bool *visited)
{
    stack<int> st;
    st.push(sv);
    visited[sv] = true;
    while(st.size() != 0)
    {
        int top = st.top();
        st.pop();
        cout << top << " ";
        for(int i = n; i >= 0; i--)
        {
            if(i == top) continue;
            if(edges[top][i] == 1)
            {
                if(visited[i]) continue;
                visited[i] = true;
                st.push(i);
            }
        }
    }
}

void print_BFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> st;
    visited[sv] = true;
    st.push(sv);
    while (st.size() != 0)
    {
        int front = st.front();
        st.pop();
        cout << front << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == front) continue;
            if (edges[front][i] == 1)
            {
                if (visited[i]) continue;
                visited[i] = true;
                st.push(i);
            }
        }
    }
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

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    cout << "DFS: ";
    print_DFS(edges, n, 0, visited);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    cout << "DFS_stack: ";
    print_DFS_stack(edges, n, 0, visited);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    cout << "BSF: ";
    print_BFS(edges, n, 0, visited);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
        delete[] edges;
    }
    delete[] visited;
    return 0;
}