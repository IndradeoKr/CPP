#include <bits/stdc++.h>
using namespace std;

void replace_character(char s[], char c1, char c2)
{
    if (s[0] == '\0')
    {
        return;
    }
    replace_character(s + 1, c1, c2);
    if(s[0] == c1)
        s[0] = c2;
}

int main()
{
    char str[100];
    char c1, c2;

    cout << "Enter a string" << endl;
    cin >> str;
    cout << "choose a character which you want to replace" << endl;
    cin >> c1;
    cout << "Choose a character by which you want to replace" << endl;
    cin >> c2;

    replace_character(str, c1, c2);

    cout << str << endl;
    return 0;
}