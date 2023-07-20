#include <bits/stdc++.h>
using namespace std;

// stack<int> reverse(stack<int> s1, stack<int> s2, int size)
// {
//     if(size == 0)
//     {
//         return s2;
//     }
//     int x = s1.top();
//     s1.pop();
//     s2.push(x);
//     reverse(s1, s2, size-1);
//     return s2;
// }

int main()
{
    stack<int> s1;
    stack<int> s2;
    int size = 4;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.pop();
    s2 = s1;
    s2.pop();
    for(int i = 0; i < 3; i++)
    {
        cout << s1.top();
        s1.pop();
    }
    // s2 = reverse(s1, s2, size);
    // for(int i = 0; i < 4; i++)
    // {
    //     cout << s2.top();
    //     s2.pop();
    // }
    return 0;
}