#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    int n;
    cout << "Enter number:\n";
    cin >> n;
    cout << "Enter string\n";
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    int q;
    cout << "Enter number\n";
    cin >> q;
    cout << "Enter string of which you want frequency\n";
    while(q--)
    {
        string s;
        cin >> s;
        cout << m[s] << endl;
    }
    return 0;
}