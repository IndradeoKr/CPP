#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size pf array\n";
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //sort(a,a+n); //for array
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}