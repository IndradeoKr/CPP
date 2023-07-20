#include <iostream>
using namespace std;

void check(int a[], int size, int num)
{
	if(size == 0)
	{
		cout << "false" << endl; 
	}
	else
	{
		if(a[0] == num)
		{
			cout << "true" << endl;
		}
		else
		{
			check(a+1, size-1, num);
		}
	}
	
}

int main()
{
	int n;
	cout << "Enter size of array" << endl;
	cin >> n;
	int *p = new int [n];
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	int n2;
	cout << "Enter any number you want to check whether it is inside array or not" << endl;
	cin >> n2;
	check(p, n, n2);
	return 0;
}	