#include <bits/stdc++.h>
using namespace std;

void print(unordered_set<string> &s)
{
    for (auto value : s)
    {
        cout << value << endl;
    }
}

int main()
{
    // set-> stored unique elements.
    unordered_set<string> s;
    s.insert("abc"); // 0(1)
    s.insert("zsdf");
    s.insert("bcd");
    auto it = s.find("abc"); // 0(1)
    if (it != s.end())
        cout << (*it) << endl;
    else
        cout << "No value\n";
    if (it != s.end())
        s.erase(it); // 0(1)
    // print(s);
    return 0;
}