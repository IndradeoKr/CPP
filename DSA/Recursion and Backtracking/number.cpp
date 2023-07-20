#include <bits/stdc++.h>
using namespace std;

void number(int num)
{
    cout << num << " ";
    if(num > 1)
    {
        number(num-1);
    }
    cout << num << " "; 

}

int main()
{
    int num;
    cout << "Enter any number" << endl;
    cin >> num;
    cout << num % 10 << endl;
    cout << num / 10 << endl;
    number(num);
    
    return 0;
}