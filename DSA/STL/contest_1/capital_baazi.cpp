#include <bits/stdc++.h>
using namespace std;

char upper(char c)
{
    return ('A' + (c - 'a'));
}

int main()
{
    while(true)
    {
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++)
        {
            s[i] = upper(s[i]);
        }
        cout << s << endl;
        if(s.length() == 0)
        {
            break;
        }
    }
    return 0;
}