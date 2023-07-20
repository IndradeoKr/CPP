#include <bits/stdc++.h>
using namespace std;

int string_to_integer(string str, int size, int start, int integer)
{
    if (size == 0)
    {
        return integer;
    }

    integer = (integer * 10) + (str[start]-48);
    int a = string_to_integer(str, size-1, start+1, integer);

    return a;
}

int main()
{
    string str;

    cout << "Enter any numbers" << endl;
    cin >> str;

    int size = str.length();

    cout << string_to_integer(str, size, 0, 0);

    return 0;
}