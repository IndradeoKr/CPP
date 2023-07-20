#include <bits/stdc++.h>
using namespace std;

void permutation(char *str, int i)
{
    if (str[i] == '\0')
    {
        cout << str << " ";
        return;
    }
    for (int j = i; str[j] != '\0'; j++)
    {
        swap(str[i], str[j]);
        permutation(str, i + 1);
        //backtracking - to restore the original array.
        swap(str[i], str[j]);
    }
}

int main()
{
    int size;

    cout << "Enter the size of string" << endl;
    cin >> size;

    char *str = new char[size];

    cin >> str;

    permutation(str, 0);
    cout << endl;
    return 0;
}