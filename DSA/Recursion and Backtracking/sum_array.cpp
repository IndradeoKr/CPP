#include <iostream>
using namespace std;

int array_sum(int a[], int size, int store)
{
	if(size == 0)
    {
        return 0;
    }
    int ans = array_sum(a+1, size-1, store);
    return ans+a[0];
}

int main()
{
	int n;
	cout << "Enter the size of array" << endl;
	cin >> n;
	int *p = new int[n];
    cout << "Enter array" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	cout << array_sum(p, n, 0) << endl;
	
	return 0;
}	