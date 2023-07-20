#include <iostream>
using namespace std;


int first_index(int a[], int size, int x)
{
	if(size == 0)
		return -1;
	if(a[0] == x)
		return 0;
	int ans = first_index(a+1, size-1, x);
	if(ans == -1)
		return -1;
	return ans+1;	
}


int main()
{
	int n;
	cout << "Enter the size of array" << endl;
	cin >> n;
	int *p = new int [n];
	cout << "Enter " << n << " size of array" << endl;
	for(int i = 0; i < n; i++)
		cin >> p[i];
	int num;
	cout << "Enter the number you want location" << endl;
	cin >> num;
	cout << first_index(p, n, num);
	return 0;
}	