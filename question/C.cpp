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
#define fi(i, n) for (int i = 0; i < n; i++)
#define fd(i, n) for (int i = n; i >= 0; i--)
#define F first
#define S second
/**********************************************************/
const int INF = 1e17;
const int NINF = -INF;
/**********************************************************/

void solve()
{
    int n, m;
    cin >> n >> m;
    vv(char) v(n, V(char)(m,'#'));
    bool flag = true;
    fi(i,n)
    {
        if(i%2 != 0)
        {
            if(flag)
            {
                for(int j = 0; j < m-1; j++) v[i][j] = '.';
            }
            else
            {
                for(int j = 1; j < m; j++) v[i][j] = '.';
            }
            flag = !flag;
        }
    }
    fi(i, n)
    {
        fi(j, m)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}