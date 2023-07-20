#include <bits/stdc++.h>
using namespace std;

// subsequence function.
int subs(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallString = input.substr(1);
    int smallOutputSize = subs(smallString, output);

    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return (2 * smallOutputSize);
}

int main()
{
    string s;

    cout << "Enter string" << endl;
    cin >> s;

    int size = pow(2, s.size());

    string *output = new string[size];

    int count = subs(s, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << " " << endl;
    }

    return 0;
}