#include <bits/stdc++.h>
using namespace std;

char *pair_star(char str[], int size, int start)
{
    if(str[start] == '\0' || str[start+1] == '\0')
        return str;
    pair_star(str, size, start+1);
    if(str[start] == str[start+1])
    {
        for(int i = strlen(str); i >= start+1; i--)
        {
            str[i+1] = str[i];
        }
        str[start+1] = '*';
        return str;
    }
    return str;
}

int main()
{
    int size;

    cout << "Enter the size of array" << endl;
    cin >> size;

    char *str = new char[size];

    cout << "Enter a string" << endl;
    cin >> str;
    cout << pair_star(str, size, 0);
    return 0;
}