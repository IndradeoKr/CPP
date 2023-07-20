#include <iostream>
using namespace std;

int helper( p, int end, int start)
{
	if (p[start] != p[end])
		return 0;
	if (start == end - 1 || start == end - 2)
		return 1;
	int ans = helper(p, end - 1, start + 1);
	return ans;
}

int checkPalindrom( p, int size)
{
	int x = helper(p, size - 1, 0);
	return x;
}

int main()
{
	int count = 0;
	 p;
	cout << "***************This program is case sensitive***************" << endl;
	cout << "Enter a " << endl;
	cin >> p;
	for (int i = 0; p[i] != '\0'; i++)
	{
		count++;
	}
	cout << count << endl;
	int ans = checkPalindrom(p, count);
	if (ans == 1)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}