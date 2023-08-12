#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
/* Template */
template<class T>  using indexed_set = tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;
/**********************************************************/

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
const int mod = 1e9+7;
/**********************************************************/

class Solution
{
public:
    void solve()
    {
        int n; cin >> n;
        indexed_set<int> s;
        for(int i = 0; i < n; i++)
        {
            int x; cin >> x;
            s.insert(x);
        }

        int cnt = 0;
        while(!s.empty())
        {
            int cur = *s.find_by_order(0);
            s.erase(cur);
            if(cur%2 == 1) continue;
            cnt++;
            s.insert(cur/2);
        }
        cout << cnt << endl;
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
    }
}