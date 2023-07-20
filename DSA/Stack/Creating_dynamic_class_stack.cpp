#include <bits/stdc++.h>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    // return the number of elements present in my stack
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0; // nextIndex = 0 -> true.//nextIndex != 0 -> false
    }

    // insert element
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            int *newdata = new int[2 * capacity];
            for(int i = 0; i < capacity; ++i)
            {
                newdata[i] = data[i];
            }
            //cout << "Stack full " << endl;
            //return;
            capacity *= 2;
            delete [] data;
            data = newdata;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // delete element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};