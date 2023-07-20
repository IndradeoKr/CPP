#include <bits/stdc++.h>
using namespace std;

class myarray
{
    int *ptr, total_size, used_size;

public:
    myarray(int tsize, int usize)
    {
        ptr = (int *)malloc(total_size * (sizeof(int)));
        total_size = tsize;
        used_size = usize;
    }
    void setdata();

    void getdata();
};

void myarray :: setdata()
    {
        cout << "Enter the value of pointer" << endl;
        for (int i = 0; i < used_size; i++)
        {
            cin >> ptr[i];
        }
    }


void myarray :: getdata()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << ptr[i] <<" " ;
        }
    }


int main()
{
    int a, b;
    cout << "Enter the total size of array" << endl;
    cin >> a;
    cout << "Enter the used size of array" << endl;
    cin >> b;
    myarray c(a, b);
    c.setdata();
    c.getdata();
return 0;
}