#include <bits/stdc++.h>
using namespace std;

void print(multiset<string> &s)
{
    for (auto value : s)
    {
        cout << value << endl;
    }
}

int main()
{
    multiset<string> s;
    s.insert("abc");// 0(log(n))
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");
    // auto it = s.find("abc");// 0(log(n))
    // if(it != s.end())
    //     s.erase(it);// it can delete value that present on that iterator.
    //s.erase("abc");//it can delete all abc that present in set
    print(s);
    return 0;
}