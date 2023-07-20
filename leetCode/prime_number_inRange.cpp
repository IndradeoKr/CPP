#include <bits/stdc++.h>
using namespace std;

/* n(log(log(n))) */

int main()
{
    int n;
    cin >> n;
    vector<bool> prime(n+1,true);

    for(int i = 2; i*i <= n; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    vector<int> res;
    
    for(int i = 2; i <= n; i++)
    {
        if(prime[i]) res.push_back(i);
    }

    for(auto it:res) cout << it << " ";
    cout << endl;
}