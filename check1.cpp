#include <bits/stdc++.h>
using namespace std;
long long arr[200000];
int main()
{
  long N, L, R;
  cin >> N >> L >> R;
  // vector<pair<int,int>> vp;
  // for(int i = 1; i <= N; i++)
  // {
  //   for(int j = i+1; j <= N; j++)
  //   {
  //     vp.push_back({i,j});
  //   }
  // }
  long long count = 0;
  for(long i = 0; i < N; i++)
  {
    arr[i] = i+1;
  }
  // vector<pair<int,int>> vp;
  for(long i = 1; i <= N; i++)
  {
    for(long j = i+1; j <= N; j++)
    {
      count++;
      // if(count > R) break;
      // if(count >= L)
      // {
      //   swap(arr[i-1],arr[j-1]);
      // }
    }
  }
  //cout << vp[37-1].first << " " << vp[37-1].second << endl;
  // for(int i = L; i <= R; i++)
  // {
  //   int f = vp[i-1].first;
  //   int s = vp[i-1].second;
  //   swap(arr[f-1],arr[s-1]);
  // }
  cout << count << endl;
  for(long i = 0; i < N; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}