#include<bits/stdc++.h> 
using namespace std;
using  ll = long long int;

int main()
{
    vector<ll> v(18,0);
    for(int i = 1; i < 18; i++)
    {
        v[i] = 9*pow(10,i-1)*i;
    }

    int q;
    cin >> q;
    while(q--)
    {
        ll k;
        cin >> k;
        if(k < 10)
        {
            cout << k << endl;
        }
        else
        {
            ll sum = 0;
            int length = 0;
            for(int i = 1; i < 18; i++)
            {
                sum += v[i];
                if(sum <= k)
                {
                    length = i+1;
                }
                else break;
            }
            // cout << "length of digit = " << length << endl;

            sum -= v[length];
            // cout << "start = " << sum << endl;
            ll remain = k-sum;
            //cout << "remaining  = " << remain << endl;
            ll start = pow(10,length-1);
            // cout << "start = " << start << endl;
            ll actuall = remain/length + start - 1;
            // cout << "actuall number = " << actuall << endl;
            ll index = remain%length;
            // cout << index << endl;
            if(index == 0) cout << actuall%10 << endl;
            else
            {
                actuall++;
                string ans = to_string(actuall);
                cout << ans[index-1] << endl;
            }
        }
    } 
    return 0;
}
