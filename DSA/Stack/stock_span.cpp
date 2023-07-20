#include <bits/stdc++.h>
using namespace std;

void spam(stack<int> stock, stack<int> temp, stack<int> &ans, int size)
{
    int count, x, y;
    for (int i = 0; i < size; i++)
    {
        count = 1;
        x = stock.top();
        stock.pop();
        temp = stock;
        for (int j = 0; j < size - (i + 1); j++)
        {
            y = temp.top();
            temp.pop();
            if (x > y)
                count++;
            else
                break;
        }
        ans.push(count);
    }

}

int main()
{
    stack<int> stock, temp, ans;
    int x, y, size;

    cout << "Input size of stock: " << endl;
    cin >> size;
    cout << "Input stock: " << endl;
    for (int i = 0; i < size; i++)
    {
        int st;
        cin >> st;
        stock.push(st);
    }
    
    spam(stock, temp, ans, size);

    cout << "\nStock spam: " <<endl;
    for (int i = 0; i < size; i++)
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}