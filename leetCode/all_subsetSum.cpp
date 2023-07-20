#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/* .......................................print unique subset sum....................................... */
// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

//   int n;
//   cin >> n;
  
//   bitset<100001> dp;
//   dp[0] = 1;

//   for(int i = 0; i < n; i++)
//   {
//     int x;
//     cin >> x;
//     dp |= dp << x;
//   }
//   vector<int> possible;

//   for(int i = 1; i <= 100001; i++)
//   {
//     if(dp[i]) possible.push_back(i);
//   }

//   cout << possible.size() << endl;

//   for(auto it:possible) cout << it << " ";
//   cout << endl;
//4 10
//4 8 6 1 }


/* .......................................using bitsmasking all possible sum....................................... */
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    for(int i = 0; i < 1<<n; i++)
    {
        ll cur_sum = 0;
        for(int j = 0; j < n; j++)
        {
            if(i>>j&1)
            {
                cur_sum += arr[j];
            }
        }
        cout << cur_sum << " ";
    }
    return 0;
}