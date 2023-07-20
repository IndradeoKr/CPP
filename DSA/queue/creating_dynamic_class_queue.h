template <typename T>
class QueueUsingArray
{
    T *data;
    int nxtIndex;
    int firstINdex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        nxtIndex = 0;
        firstINdex = -1;
        size = 0;
        capacity = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *newData = new T[2 * capacity];
            int j = 0;
            for(int i = firstINdex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for(int i = 0; i < firstINdex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete []data;
            data = newData;
            firstINdex = 0;
            nxtIndex = capacity;
            capacity *= 2; 
        }
        data[nxtIndex] = element;
        nxtIndex = (nxtIndex + 1) % capacity;
        if (firstINdex == -1)
            firstINdex = 0;
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return data[firstINdex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty !!" << endl;
            return 0;
        }
        T ans = data[firstINdex];
        firstINdex = (firstINdex + 1) % capacity;
        size--;
        if (size == 0) // not important.
        {
            firstINdex = -1;
            nxtIndex = 0;
        }
        return ans;
    }
};