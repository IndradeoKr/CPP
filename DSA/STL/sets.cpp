#include <bits/stdc++.h>
using namespace std;

void print(set<string> &s)
{
    for(auto value : s)
    {
        cout << value << endl;
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8};
    int a = v.back();
    cout << a;
    //set-> stored unique elements.
    set<string> s;
    s.insert("abc");// 0(log(n))
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("zsdf");
    s.insert("zsdf");
    print(s);
    auto it = s.find("abc");// 0(log(n))
    auto i = s.end();
    i--;
    cout << *i << "123456"  << endl;
    if(it != s.end())
        cout << (*it) << endl;
    else
        cout << "No value\n";
    if(it != s.end())
        s.erase(it);// 0(log(n))
    //print(s);

    return 0;
}