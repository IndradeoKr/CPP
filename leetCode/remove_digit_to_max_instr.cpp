#include <bits/stdc++.h>
using namespace std;

string removeDigit(string number, char digit)
{
    string s;
    vector<int> vc;
    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] == digit)
        {
            vc.push_back(i);
        }
    }
    int index;
    for (int i = 0; i < vc.size(); i++)
    {
        if (vc[i] == vc.size() - 1)
        {
            index = vc[i];
        }
        else if (number[vc[i]] < number[vc[i] + 1])
        {
            index = i;
        }
    }
    for (int i = 0; i < number.size(); i++)
    {
        if (i == index)
            continue;
        s = s + number[i];
    }
    return s;
}

int main()
{
    string s = {"551"};
    char c = {'5'};
    string ans = removeDigit(s,c);
    cout << ans;
    return 0;
}