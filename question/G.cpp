#include <bits/stdc++.h>
using namespace std;
 
/*macro function*/
#define all(x) x.begin(), x.end()
#define int long long int
#define PQ(x) priority_queue<x, vector<x>, greater<x>>
#define tiii tuple<int, int, int>
#define tiic tuple<int, int, char>
#define tici tuple<int, char, int>
#define tcii tuple<char, int, int>
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pb push_back
#define V(x) vector<x>
#define vv(x) vector<vector<x>>
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fd(i, a, n) for (int i = a; i >= n; i--)
#define F first
#define S second
/**********************************************************/
const int INF = 1e17;
const int NINF = -INF;
/**********************************************************/



signed main()
{
    string s,t;
    cin >> s;
    cin >> t;

    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    fi(i,1,n+1)
    {
        fi(j,1,m+1)
        {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    string res = "";

    int i = n, j = m;
    while(i >= 1 && j >= 1)
    {
        if(s[i-1] == t[j-1])
        {
            res += s[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] < dp[i][j-1]) j--;
            else i--;
        }
    }
    reverse(all(res));
    cout << res << endl;
}