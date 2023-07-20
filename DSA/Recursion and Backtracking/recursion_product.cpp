#include <iostream>
using namespace std;

int product(int n, int m)
{
	if(m == 0)
		return 0;
	int ans = product(n, m-1);
		return ans+n;
	
}

int main()
{
	int n, m, temp;
	cout << "Enter any two number" << endl;
	cin >> n >> m;
	if(n < m)
	{
		temp = n;
		n = m;
		m = temp;
	}
	cout << product(n, m);
	
	return 0;
}	