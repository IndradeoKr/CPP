#include <bits/stdc++.h>
using namespace std;

void RmDuplicate(char s[])
{
    if(s[0] == '\0')
        return;
    
    RmDuplicate(s + 1);
    if(s[0] == s[1])
    {
        for(int i = 0; i < strlen(s); i++)
        {
            s[i] = s[i+1];
        }
    }
}

int main()
{
    char str[50];

    cout << "Enter string" << endl;
    cin >> str;

    RmDuplicate(str);

    cout << str << endl;
    return 0;
}