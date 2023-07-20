#include <bits/stdc++.h>
using namespace std;

int equilibrium(vector<int> v, int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return -1;
    int lsum = v[0];
    int rsum = v[n - 1];
    int i = 1;
    int j = n - 2;
    while (i < j)
    {
        if (lsum < rsum)
        {
            lsum += v[i];
            i++;
        }
        else if (rsum < lsum)
        {
            rsum += v[j];
            j--;
        }
        else if(rsum == lsum)
        {
            lsum += v[i];
            i++;
            rsum += v[j];
            j--;
        }
    }
    //cout << lsum << " "<< rsum << endl;
    if(lsum == rsum) return i+1;
    return -1;
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // for(int i= 0; i < n; i++)
    // {
    //     cout << v[i] << " ";
    // }
    cout << endl;
    if(equilibrium(v, n) == -1) cout << "Not found\n";
    else cout << equilibrium(v,n);
    return 0;
}