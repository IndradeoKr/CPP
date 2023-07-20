#include <iostream>
using namespace std;

int all_index(int p[], int size, int x, int count)
{
	if(size == 0)
	{
		return 0;
	}
	int ans = all_index(p, size-1, x, count-1);
	if(p[size-1] == x)
		cout << count << " "; 
	if(p[size-1] == x)
    {
	    return ans+1;
    }
	return ans;
}

int main()
{
	int n;
	cout << "Enter size of array" << endl;
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
	// cout << 
    all_index(p, n, x, n-1);
	return 0;
}	