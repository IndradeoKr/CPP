// 1/2 + 1/4 + 1/8 +.....
#include <iostream>
#include<cmath>
using namespace std;

float geometric_sum(int k, float x = 0.5)
{
	if(k == 0)
		return 1;
	float ans = geometric_sum(k-1);
	return (ans+pow(0.5,k));
}

int main()
{
	int k;
	cout << "Enter the value of k" << endl;
	cin >> k;
	cout << geometric_sum(k) << endl;
	return 0;
}	