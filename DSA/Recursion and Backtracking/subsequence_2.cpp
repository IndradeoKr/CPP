#include <bits/stdc++.h>
using namespace std;

void subsequence(char *input, char *output, int i, int j)
{
    if(input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    output[j] = input[i];

    subsequence(input, output, i+1, j+1);

    subsequence(input, output, i+1, j);
}

int main()
{
    int size;
    
    cout << "Enter the size of arr" << endl;
    cin >> size;

    char *input = new char[size];
    char *output = new char[size];

    cout << "Enter a string" << endl;
    cin >> input;

    subsequence(input, output, 0, 0);
    return 0;
}