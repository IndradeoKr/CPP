#include <bits/stdc++.h>
using namespace std;
template <typename T>
class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data = new T[4];
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
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newdata = new T[2 * capacity];
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
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};