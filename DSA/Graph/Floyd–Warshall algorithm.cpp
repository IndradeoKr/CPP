#include<bits/stdc++.h>
using namespace std;

/*macro function*/
#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vii vector<vector<ll>>
#define fi(i,a,n) for(ll i = a; i < n; i++)
#define fd(i,a,n) for(ll i = a; i >= n; i--)
#define F first
#define S second
/**********************************************************/

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
    int n,m,q;
    cin >> n >> m >> q;
    vii path(n+1,vector<ll>(n+1,LLONG_MAX));

    fi(i,1,n+1) path[i][i] = 0;
    fi(i,0,m)
    {
        int a,b,c;
        cin >> a >> b >> c;
        path[a][b] = min((ll)c,path[a][b]);
        path[b][a] = min((ll)c,path[a][b]);
    }

    fi(k,1,n+1)
    {
        fi(i,1,n+1)
        {
            fi(j,1,n+1)
            {
                if(path[i][k] == LLONG_MAX || path[k][j] == LLONG_MAX) continue;
                path[i][j] = min(path[i][j],path[i][k]+path[k][j]);
            }
        }
    }

    fi(i,0,q)
    {
        int a,b;
        cin >> a >> b;
        path[a][b] == LLONG_MAX ? cout << -1 << endl : cout << path[a][b] << endl;
    }
}