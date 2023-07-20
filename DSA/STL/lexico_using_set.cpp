#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<string> s;
    int n;
    cout << "Enter number:\n";
    cin >> n;
    cout << "Enter string:\n";
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    // cout << "\nYour unique string\n";
    // for(auto value : s)
    // {
    //     cout << value << endl;
    // }
    int q;
    cout << "Enter number to find:\n";
    cin >> q;
    while (q--)
    {
        string str;
        cout << "Enter string\n";
        cin >> str;
        if (s.find(str) == s.end())
            cout << "No\n";
        else
            cout << "yes\n";
    }
    return 0;
}