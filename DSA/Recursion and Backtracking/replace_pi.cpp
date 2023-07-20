#include <bits/stdc++.h>
using namespace std;

char *replace_pi(char input[], int start)
{
    if (input[start] == '\0' || input[start + 1] == '\0')
        return input;
    replace_pi(input, start + 1);
    if (input[start] == 'p' && input[start + 1] == 'i')
    {
        for (int i = strlen(input); i >= start + 2; i--)
        {
            input[i + 2] = input[i];
        }
        input[start] = '3';
        input[start + 1] = '.';
        input[start + 2] = '1';
        input[start + 3] = '4';
        return input;
    }
    return input;
}

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    char *input = new char[n];
    cout << "Enter a string" << endl;
    cin >> input;
    cout << replace_pi(input, 0) << endl;
    return 0;
}