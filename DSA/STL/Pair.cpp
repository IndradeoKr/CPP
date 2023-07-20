#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair <int, string> p;
    cin >> p.first >> p.second;
    cout << p.first << p.second;
    //p = make_pair(2, "abc");
    //alter
    // p = {2, "abcd"};
    // //pair <int, string> p1 = p; //Only a copy of p is passes to p1.
    // pair <int, string> &p1 = p;//to change the value in p. we need to take reference.
    // p1.first = 3;
    // cout << p.first << " " << p.second << endl;
    
    // pair <int, int> p_array[3];
    // p_array[0] = {1,2};
    // p_array[1] = {3,4};
    // p_array[2] = {5,6};
    // for(int i = 0; i < 3; ++i)
    // {
    //     cout << p_array[i].first << " " << p_array[i].second << endl;
    // }
    // swap(p_array[0],p_array[1]);
    // cout << "after swaping" << endl;
    // for(int i = 0; i < 3; ++i)
    // {
    //     cout << p_array[i].first << " " << p_array[i].second << endl;
    // }
    return 0;
}