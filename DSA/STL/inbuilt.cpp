#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int min = *min_element(v.begin(), v.end());//to find minimum
    cout << min << endl;
    int max = *max_element(v.begin(), v.end());//to find maximum
    cout << max << endl;
    int sum = accumulate(v.begin(), v.end(),0);//to find sum of array
    cout << sum << endl;
    int ct = count(v.begin(), v.end(),6);//to find how many three number are present in array
    cout << ct << endl;
    auto it = find(v.begin(), v.end(), 26);//to find element in array
    if(it != v.end())
        cout << *it << endl;
    else
        cout << "Element not find" << endl;
    reverse(v.begin(), v.end());// to reverse a array
    for(auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    string s = "abcdefgh";
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}