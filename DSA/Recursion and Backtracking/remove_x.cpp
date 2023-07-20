#include <bits/stdc++.h>
using namespace std;

char *remove_x(char input[], int start)
{
    if (input[start] == '\0' && input[start + 1] == '\0')
        return input;
    remove_x(input, start + 1);
    if (input[start] == 'x')
    {
        for (int i = start; input[start] != '\0'; start++)
            input[start] = input[start + 1];
        return input;
    }
    return input;
}

int main()
{
    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    char *input = new char[size];
    cout << "Enter string" << endl;
    cin >> input;
    cout << remove_x(input, 0) << endl;
    return 0;
}