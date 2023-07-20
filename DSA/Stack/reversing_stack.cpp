#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int> s1, stack<int> &s2, int size)
{
    if(size == 0)
    {
        return;
    }
    int x = s1.top();
    s1.pop();
    reverse(s1, s2, size-1);
    s2.push(x); 
    return;
}

int main()
{
    stack<int> s1;
    stack<int> s2;
    int size;
    cout << "Input the size of stack" << endl;
    cin >> size;
    cout << "Input elements of stack" << endl;
    for(int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        s1.push(x);
    }
    reverse(s1, s2, size);
    cout << "Before reversing the stack: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << s1.top() << endl;
        s1.pop();
    }
    for(int i = 0; i < size; i++)
    {
        int x = s2.top();
        s2.pop();
        s1.push(x);
    }
    cout << "After reversing the stack: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << s1.top() << endl;
        s1.pop();
    }
    return 0;
}