#include <bits/stdc++.h>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printkeypadString(char *input, char *output, int i, int j)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    int digit = input[i] - '0';

    if (digit == 1 || digit == 0)
        printkeypadString(input, output, i + 1, j);

    for (int k = 0; keypad[digit][k] != '\0'; k++)
    {
        output[j] = keypad[digit][k];
        printkeypadString(input, output, i + 1, j + 1);
    }
}

int main()
{
    int size;

    cout << "Enter the size of array" << endl;
    cin >> size;

    char *in = new char[size];
    char *out = new char[size];

    cout << "Enter a string" << endl;
    cin >> in;

    printkeypadString(in, out, 0, 0);
    return 0;
}