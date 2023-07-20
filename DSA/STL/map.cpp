#include <bits/stdc++.h>
using namespace std;

void print(map<int, string> &m)
{
    cout << m.size() << endl;
    for (auto &it : m)
    {
        cout << (it.first) << " " << (it.second) << endl;
    }
}

int main()
{
    //time complexity depends on key words. -> sizeof()*log(n)
    // map<key, elements> -> keys is unique in map.
    map<int, string> m; // keys stored in sorted form.
    m[1] = "abc";       // 0(log(n))
    m[5] = "cdc";
    m[3] = "acd";
    m.insert({4, "afg"});
    auto it = m.find(5); // it returns iterator.if value is not present than it returns m.end()
    if(it != m.end())// to check if its exits or not
        m.erase(it);//using iterator
    // m.find() -> 0(log(n))
    m.erase(3); // it takes iterator or direct value to earse.
    // m.erase->0(log(n))
    //m.clear(); -> to clear all elements at once
    //  if (it == m.end())
    //  {
    //      cout << "No Value\n";
    //  }
    //  else
    //  {
    //      cout << (it->first) << " " << it->second << endl;
    // }
    print(m);
    return 0;
}