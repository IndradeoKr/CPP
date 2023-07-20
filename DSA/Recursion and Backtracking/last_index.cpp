#include <iostream>
using namespace std;


int last_index(int a[], int size, int x)
{
	if(size == 0)
		return -1;
	int ans = last_index(a+1 , size-1, x);
	if(ans != -1)
		return ans+1;
	if(a[0] == x)
		return 0;
	else
		return -1;
}


int main()
{
	int n;
	cout << "Enter size of array" << endl;
	cin >> n;
	int *p = new int [n];
	cout << "Enter " << n << " of array" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	int num;
	cout << "Enter any number" << endl;
    cin >> num;
	cout << last_index(p, n, num) << endl;
	
	return 0;
}	