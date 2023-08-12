#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
/* Template */
template<class T>  using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


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

class SEGtree{
private:
    vector<int> seg,lazy;
public:
    SEGtree(int n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1,0);
    }

    void build(int ind, int low, int high, vector<int> &arr)
    {
        if(low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)/2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        seg[ind] = (seg[2*ind+1]+seg[2*ind+2]);
    }

    int query(int ind, int low, int high, int l ,int r)
    {
        if(r < low || high < l)
        {
            return 0;
        }

        if(l <= low && high <= r) return seg[ind];

        int mid = (low+high)/2;

        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);

        return (left+right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if(low == high)
        {
            seg[ind] += val;
            return;
        }

        int mid = (low+high)/2;

        if(i <= mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);

        seg[ind] = (seg[2*ind+1]+seg[2*ind+2]);
    }

    void rangeUpadate(int ind, int low, int high, int l, int r, int val)
    {
        //if updates are remaining update and then propagate downward.
        if(lazy[ind] != 0)
        {
            seg[ind] += (high-low+1)*lazy[ind];

            //if lower nodes are available than transfer the remaining val;
            if(low != high)
            {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        //[l, r, low, high] or [low, high, l, r]
        if(r < low || high < l) return;

        //[l, low, high, r]
        if(l <= low && high <= r)
        {
            seg[ind] += (high-low+1)*val;

            if(low != high)
            {
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }

        int mid = (low+high)/2;
        rangeUpadate(2*ind+1,low,mid,l,r,val);
        rangeUpadate(2*ind+2,mid+1,high,l,r,val);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    int rangeQuery(int ind, int low, int high, int l ,int r)
    {
        //if updates are remaining update and then propagate downward.
        if(lazy[ind] != 0)
        {
            seg[ind] += (high-low+1)*lazy[ind];

            //if lower nodes are available than transfer the remaining val;
            if(low != high)
            {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(r < low || high < l)
        {
            return 0;
        }

        if(l <= low && high <= r) return seg[ind];

        int mid = (low+high)/2;

        int left = rangeQuery(2*ind+1,low,mid,l,r);
        int right = rangeQuery(2*ind+2,mid+1,high,l,r);

        return (left+right);
    }
};

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n; cin >> n;

    vector<int> v(n);
    for(auto &it:v) cin >> it;

    SEGtree s(n);
    s.build(0,0,n-1,v);

    int q; cin >> q;

    while(q--)
    {
        int type; cin >> type;

        if(type == 1)
        {
            int l,r; cin >> l >> r;

            cout << s.rangeQuery(0,0,n-1,l,r) << endl;
        }
        else
        {
            int l,r,val; cin >> l >> r >> val;

            s.rangeUpadate(0,0,n-1,l,r,val);
        }
    }
}