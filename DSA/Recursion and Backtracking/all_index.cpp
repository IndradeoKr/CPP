#include <iostream>
using namespace std;

int all_index(int a[], int size, int x, int count)
{
	if(size == 0)
	{
		cout << endl;
		return 0;
	}
	if(a[0] == x)
		cout << count << " ";
	int ans = all_index(a+1, size-1, x, count+1);
	if(a[0] == x)
		return ans+1;
	return ans;
}

int main()
{
	int n;
	cout << "Enter the size of array" << endl;
	cin >> n;
	int *p = new int [n];
	cout << "Enter array" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	int x;
	cout << "Enter number to find" << endl;
	cin >> x;
	cout << all_index(p, n, x, 0) << endl;
	return 0;
}	