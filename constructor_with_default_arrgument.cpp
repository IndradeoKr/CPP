#include <bits/stdc++.h>
using namespace std;
class simple{
    int data1;
    int data2;
    int data3;
    public:
    simple(int a, int b=9, int c=4)
    {
        data1 = a;
        data2 = b;
        data3 = c;

    }
    void print();
};
void simple :: print()
{
    cout << "the value of data1, data2 and data3 are " << data1 << ", " <<data2 << " and " << data3 << ", respectivly" <<  endl; 
}
int main()
{
    simple c(10);
    c.print();
    
    return 0;
}