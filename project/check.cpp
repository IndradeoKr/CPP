#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "aabbbaa";
    while (s.size() > 0)
    {
        if (s.front() != s.back())
            cout << "Not palindron\n";
        s.pop_back();
        s = s.substr(1);
    }
    cout << "Palindrom\n";
    return 0;
}