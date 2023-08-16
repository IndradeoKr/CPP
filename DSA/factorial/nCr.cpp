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



/**************************************************
                    Constraints:
                    1 ≤ r, n ≤ 105


                    (a/b)%mod = (a%mod) * (((b)^-1)%mod)
                              = (a%mod) * ((b)^(mod-2))
***************************************************/


class Solution{
    const int mod = 1e9+7;
public:
    long long binpow(long long a,int b){
       long long res = 1;
       while(b > 0){
           if(b & 1){ //odd number
               res = (res*a)%mod;
           }
           a = (a*a)%mod;
           b >>= 1;
       }
       return res;
   }
   
   long long ncr(long long n, long long r){
       long long fact[n+1], inv[n+1];
       fact[0] = inv[0] = 1;
       
       for(int i=1;i<=n;i++){
           fact[i] = (i*fact[i-1])%mod;
       }
       
       for(int i=1;i<=n;i++){
           inv[i] = binpow(fact[i],mod-2);
       }
       
       if(r > n)return 0;
       else return ((fact[n]*inv[r])%mod*inv[n-r])%mod;
   }
};

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    int t=1;
    // cin >> t;
    while(t--)
    {
        Solution s;
        int n,r; cin >> n >> r;
        cout << s.ncr(n,r) << endl;
    }
}
