// 0->water and 1->land
#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &edges, vector<vector<int>> &visited)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;
    int n = edges.size();
    int m = edges[0].size();
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        // traversal in all 8 directions.
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nrow = r + i;
                int ncol = c + j;
                if (nrow < n && nrow >= 0 && ncol < m && nrow >= 0 && !visited[nrow][ncol] && edges[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
    }
}

void createGraph(vector<vector<int>> &edges, int e)
{
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
}

int main()
{
    int n, e;
    cout << "Enter number of vertices and edges\n";
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    createGraph(edges, e);
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && edges[i][j] == 1)
            {
                count++;
                bfs(i, j, edges, visited);
            }
        }
    }
    cout << "Number or islands are " << count << endl;
    return 0;
}