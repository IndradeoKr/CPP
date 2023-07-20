#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cout << "Enter number of tests case.\n";
    cin >> t;
    while(t--)
    {
        int n, k;
        cout << "Enter number of bags and minutes\n";
        cin >> n >> k;
        multiset<long long> bags;
        for(int i = 0; i < n; i++)
        {
            long long candy;
            cin >> candy;
            bags.insert(candy);
        }
        long long candy_count = 0;
        for(int i = 0; i < k; i++)
        {
            auto last_it = (--bags.end());
            long long candy_ct = *last_it;
            candy_count += candy_ct;
            bags.erase(last_it);
            bags.insert(candy_ct/2);
        }
        cout << candy_count << endl;
    }
    return 0;
}