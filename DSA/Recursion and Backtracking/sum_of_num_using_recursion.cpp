#include <iostream>
using namespace std;

int sum(int n)
{
	if(n / 10 == 0)
		return n%10;
	int ans = sum(n/10);
	return ans + n%10;
}

int main()
{
	int n;
	cout << "Enter a number" << endl;
	cin >> n;
	cout << sum(n) << endl;
	return 0;
}