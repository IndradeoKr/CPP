#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<int, string> &m)
{
    cout << m.size() << endl;
    for (auto &it : m)
    {
        cout << (it.first) << " " << (it.second) << endl;
    }
}

int main()
{
    //1. Inbuilt implementation
    //2. Time complexity
    //3. Valid keys datatype
    unordered_map<int, string> m;
    m[1] = "abc"; //0(1)
    m[5] = "cdc";
    m[3] = "acd";
    m[6] = "a";
    m[5] = "cde";
    unordered_map<int, int> m1;
    m1[1] = 12;
    auto it = m.find(4); //0(1)
    if(it != m.end())
    {
        m.erase(it); //0(1)
    }
    cout << m[1];
    print(m);
    return 0;
}