#include<bits/stdc++.h>
using namespace std;

int fre(int n, int frequency[], int arr1[])
{
	for(int i = 0; i < n; i++)
	{    								   // 0 1 2 3 4 5 -> index of array
		frequency[arr1[i]]++; // 1 1 2 2 3 -> 0 2 2 1 0 0
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(frequency[i] > 1) cnt++;
	}
	return cnt;
}

void finder(int n, int frequency[], int arr2[])
{
	int i = 0; // for frequency
	int k = 0; // for arr2
	while(i < n)
	{
		if(frequency[i] > 1)
		{
			arr2[k++] = i;
		}
		i++;
	}
}

int main()
{
	int n;
	cout << "Enter size of array\n";
	cin >> n;
	int arr1[n];
	for(int i = 0; i < n; i++)
	{
		int t;
		cout << "Enter element of array\n";
		cin >> t;
		if(t < n)
		{
			arr1[i] = t;
		}
		else
		{
			cout << "Try to enter a number less than " << n << endl;
			i--;
		}
	}

	for(int i = 0; i < n; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	int frequency[n]; // to store the frequency of elements;
	for(int i = 0; i < n; i++) // intially all elements are 0;
	{
		frequency[i] = 0;
	}
	int x = fre(n,frequency,arr1);

	int arr2[x]; // to store reccuring number.

	finder(n,frequency,arr2);

	for(int i = 0; i < x; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
// 	int n;
// 	cout << "Enter number\n";
// 	cin >> n;
	
// 	long x = 0*1l;
// 	long y = 1*1l;
// 	for(int i = 0; i < n; i++)
// 	{
// 		y = (x = x + y) - y;
// 	}
	
// 	cout << x;
	
// 	return 0;
// }