#include <iostream>
using namespace std;
#include <queue>

int main()
{
    queue<int> q;

    q.push(10);// used to inster a value.
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl; // used to print the front element.
    q.pop(); //used to delete the front element.
    cout << q.front() << endl;
    cout << q.size() << endl;// used to get the current size.
    cout << q.empty() << endl;// to cheack weather the queue is empty or not.

    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}