#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s)
{
    stack<char> s1;
    char x;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            s1.push(s[i]);
            continue;
        }
        if (s1.empty())
        {
            return false;
        }
        switch (s[i])
        {
        case ')':
            x = s1.top();
            s1.pop();
            if (x == '{' || x == '[')
                return false;
            break;
        case '}':
            x = s1.top();
            s1.pop();
            if (x == '(' || x == '[')
                return false;
            break;
        case ']':
            x = s1.top();
            s1.pop();
            if (x == '{' || x == '(')
                return false;
            break;
        }
    }
    return s1.empty();
}

int main()
{
    string s1;
    cout << "Enter any equation to cheack weather the expration is true or not" << endl;
    cin >> s1;
    if (isBalanced(s1))
        cout << "Expretion is balanced" << endl;
    else
        cout << "Expretion is not balanced" << endl;
    return 0;
}