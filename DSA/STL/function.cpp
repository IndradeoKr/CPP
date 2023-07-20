#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {2,3,5};
    cout << all_of(v.begin(), v.end(),[](int x){return x>0;});//if all conditions are true than it return true otherwise return false
    cout << any_of(v.begin(), v.end(),[](int x){return x>0;});//if all condtions are false than it return false otherwise return true
    cout << none_of(v.begin(), v.end(),[](int x){return x>0;});//if all condtions are false than it retrun true otherwise return false
    return 0;
}