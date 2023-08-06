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
const int N = 1e8;
/**********************************************************/

class Solution
{
    public:
    void solve()
    {
        int n,m;
        cin >> n >> m;
        for(int i = n; i <= m; i++) if(isPrime(i)) cout << i << " " << endl;
    }
    bool isPrime(int n)
    {
        // Corner case
        if (n <= 1)
            return false;
     
        // Check from 2 to square root of n
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
     
        return true;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while(t--)
    {
        Solution s;
        s.solve();
        cout << endl;
    }
}