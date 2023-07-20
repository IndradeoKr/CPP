#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<char, int> &m)
{
    for (auto &it : m)
    {
        cout << (it.first) << " " << (it.second) << endl;
    }
}

// bool check(unordered_map<char, int> &m)
// {
//     set<int> s;
//     for (auto i = m.begin(); i != m.end(); i++)
//     {
//         for (auto j = m.begin(); j != m.end(); j++)
//         {
//             if (i == j)
//                 continue;
//             s.insert(j->second);
//         }
//         if (s.size() == 1)
//             return true;
//         s.clear();
//     }
//     return false;
// }

int main()
{
    unordered_map<char, int> m;
    string str;
    cout << "Enter any string\n";
    cin >> str;
    for (auto s : str)
    {
        m[s]++;
    }
    print(m);
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    // auto it = s.begin();
    int start = *it;
    int i = 0;
    for(auto j = s.begin(); j != s.end(); j++)
        if(i == *j);
    // if(check) cout << "True\n";
    // else cout << "False\n";
    return 0;
}