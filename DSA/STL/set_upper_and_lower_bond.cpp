#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of sets" << endl;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.insert(num);
    }
    int fn;
    cout << "Enter number to find" << endl;
    cin >> fn;
    auto it = s.lower_bound(fn);
    cout << *it;
    return 0;
}