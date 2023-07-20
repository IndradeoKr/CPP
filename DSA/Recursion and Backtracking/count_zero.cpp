#include <iostream>
using namespace std;

int count_zero(int x)
{
	if(x == 0)
		return 0;
	int ans = count_zero(x/10);
	if(x%10 == 0)
		return ans+1;
	return ans;
}

int main()
{
	int x;
	cout << "Enter a number to find zeros in the number" << endl;
	cin >> x;
	cout << count_zero(x) << endl;
	return 0;
}	