#include <bits/stdc++.h>
using namespace std;

/*macro function*/
#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vii vector<vector<ll>>
#define pii pair<ll,ll>
#define pic pair<ll,char>
#define pci pair<char,ll>
#define fi(i, a, n) for (ll i = a; i < n; i++)
#define fd(i, a, n) for (ll i = a; i >= n; i--)
#define F first
#define S second
/**********************************************************/

void count_sort(vi &p, vi &c)
{
    int n = p.size();
    vi p_new(n);
    vi cnt(n);
    for(auto it:c) cnt[it]++;

    vi pos(n);
    pos[0] = 0;
    fi(i, 1, n) pos[i] = pos[i - 1] + cnt[i - 1];

    for (auto it : p)
    {
        int i = c[it];
        p_new[pos[i]] = it;
        pos[i]++;
    }
    p = p_new;
}

int main()
{
    string s;
    cin >> s;

    s += '$';

    int n = s.size();
    vi p(n), c(n);

    {
        vector<pair<char, int>> a(n);
        fi(i, 0, n)
        {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());

        fi(i, 0, n) p[i] = a[i].second;

        c[p[0]] = 0;
        fi(i, 1, n)
        {
            if (a[i].F == a[i - 1].F)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n)
    {

        fi(i,0,n) p[i] = (p[i] - (1<<k) + n)%n;

        count_sort(p,c);

        vi c_new(n);
        c_new[p[0]] = 0;

        fi(i, 1, n)
        {
            pii prev = {c[p[i-1]],c[(p[i-1] + (1<<k))%n]};
            pii now = {c[p[i]],c[(p[i] + (1<<k))%n]};

            if(prev == now) c_new[p[i]] = c_new[p[i-1]];
            else c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        c = c_new;
        k++;
    }
    fi(i, 0, n) cout << p[i] << " ";
    cout << endl;
}

/*
***************Easy One*****************************
#include <bits/stdc++.h>
using namespace std;

/*macro function

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vii vector<vector<ll>>
#define pii pair<ll, ll>
#define pic pair<ll, char>
#define pci pair<char, ll>
#define fi(i, a, n) for (ll i = a; i < n; i++)
#define fd(i, a, n) for (ll i = a; i >= n; i--)
#define F first
#define S second
/**********************************************************

void radix_sort(vector<pair<pii, ll>> &a)
{
    ll n = a.size();
    {
        vi cnt(n);
        for (auto it : a)
            cnt[it.F.S]++;

        vi pos(n);
        pos[0] = 0;
        fi(i, 1, n) pos[i] = pos[i - 1] + cnt[i - 1];

        vector<pair<pii, ll>> a_new(n);
        for (auto it : a)
        {
            int i = it.F.S;
            a_new[pos[i]] = it;
            pos[i]++;
        }
        a = a_new;
    }

    {
        vi cnt(n);
        for (auto it : a)
            cnt[it.F.F]++;

        vi pos(n);
        pos[0] = 0;
        fi(i, 1, n) pos[i] = pos[i - 1] + cnt[i - 1];

        vector<pair<pii, ll>> a_new(n);
        for (auto it : a)
        {
            int i = it.F.F;
            a_new[pos[i]] = it;
            pos[i]++;
        }
        a = a_new;
    }
}

int main()
{
    string s;
    cin >> s;

    s += '$';

    int n = s.size();
    vi p(n), c(n);

    {
        vector<pci> a(n);
        fi(i, 0, n)
        {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());

        fi(i, 0, n) p[i] = a[i].second;

        c[p[0]] = 0;
        fi(i, 1, n)
        {
            if (a[i].F == a[i - 1].F)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n)
    {
        vector<pair<pii, ll>> a(n);
        fi(i, 0, n) a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};

        radix_sort(a);

        fi(i,0,n) p[i] = a[i].second;

        c[p[0]] = 0;

        fi(i, 1, n)
        {
            if (a[i].F == a[i - 1].F)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
        k++;
    }
    fi(i, 0, n) cout << p[i] << " ";
    cout << endl;
}
*/