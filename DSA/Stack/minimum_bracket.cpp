#include <bits/stdc++.h>
using namespace std;
int main()
{
    string bracket;
    stack<char> br;
    int count = 0;

    cout << "Enter curly brackets to check how many of them have to reverse: " << endl;
    cin >> bracket;

    for (int i = 0; i < bracket.length(); i++)
    {
        if (bracket[i] == '{')
            br.push(bracket[i]);
        else if (bracket[i] == '}')
        {
            br.pop();
        }
    }
    
    if (br.size() % 2 == 0)
        cout << br.size() / 2 << endl;
    else
        cout << -1 << endl;
    return 0;
}