#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> q1, queue<int> &q2, int size)
{
    if(size == 0)
        return;
    int x = q1.front();
    q1.pop();
    reverse(q1, q2, size-1);
    q2.push(x);
    return;
}

int main()
{
    queue<int> q1;
    queue<int> q2;
    int size;

    cout << "Input size of queue: " << endl;
    cin >> size;
    cout << "Input elements of queue: " << endl;

    for(int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        q1.push(x);
    }

    reverse(q1, q2, size);

    cout << endl << "Before reversing queue: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << q1.front() << endl;
        q1.pop();
    }
    for(int i = 0; i < size; i++)
    {
        int x = q2.front();
        q2.pop();
        q1.push(x);
    }

    cout << endl << "After reversing the queue: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << q1.front() << endl;
        q1.pop();
    }

    return 0;
}