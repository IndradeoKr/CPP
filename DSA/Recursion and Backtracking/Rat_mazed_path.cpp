#include <bits/stdc++.h>
using namespace std;

bool ratMaze(char maze[10][10], int sol[10][10], int i, int j, int m, int n)
{
    if (i == m && j == n)
    {
        sol[m][n] = 1;
        // print the path.
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    if (i > m || j > n)
        return false;
    if (maze[i][j] == 'X')
        return false;
    // asssuming solution is right.
    sol[i][j] = 1;

    bool rightsucces = ratMaze(maze, sol, i, j + 1, m, n);
    bool downsucces = ratMaze(maze, sol, i + 1, j, m, n);

    // backtracking
    sol[i][j] = 0;

    if (rightsucces || downsucces)
        return true;
    return false;
}

int main()
{
    char maze[10][10] = {"0000", "00X0", "000X", "0X00"};
    int sol[10][10] = {0};
    int m = 4, n = 4;

    bool ans = ratMaze(maze, sol, 0, 0, m - 1, n - 1);

    if (ans == false)
    {
        cout << "Path does not exist !" << endl;
    }
    return 0;
}