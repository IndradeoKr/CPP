#include<bits/stdc++.h> 
using namespace std;
using  ll = long long int;

vector<vector<int>> g(7,vector<int>(7,0));
int cnt = 0;
const int totalSteps = 48;
string s;

void move(int r, int c, int k)
{
    if(r == 6 && c == 0)
    {
        
        if(totalSteps == k) cnt++;
        return;
    }

    if(((r+1 == 7 || r == 0|| c == 0 || c+1 == 7 || (g[r-1][c] && g[r+1][c])) && c-1 >= 0 && c+1 < 7 && !g[r][c-1] && !g[r][c+1]))
    {
        return;
    }
    if(((r+1 == 7 || r == 0|| c == 0 || c+1 == 7 || (g[r][c-1] && g[r][c+1])) && r-1 >= 0 && r+1 < 7 && !g[r-1][c] && !g[r+1][c]))
    {
        return;
    }
    g[r][c] = 1;
    
    if((s[k] == '?' || s[k] == 'U') && r-1 >= 0 && !g[r-1][c]) move(r-1,c,k+1);
    if((s[k] == '?' || s[k] == 'D') && r+1 < 7 && !g[r+1][c]) move(r+1,c,k+1);
    if((s[k] == '?' || s[k] == 'L') && c-1 >= 0 && !g[r][c-1]) move(r,c-1,k+1);
    if((s[k] == '?' || s[k] == 'R') && c+1 < 7 && !g[r][c+1]) move(r,c+1,k+1);
    
    g[r][c] = 0;
}
int main()
{
    cin >> s;
    int steps = 0;
    move(0,0,steps);
    cout << cnt << endl;
    return 0;
}
