#include <iostream>
using namespace std;

int countDigit(int num)
{
    if (num/10 == 0)
        return 1;
    return 1 + countDigit(num / 10);
}
int main()
{
	int num;
	cout << "Enter any number to count the digit of that number" << endl;
	cin >> num;
	cout << countDigit(num) << endl;
	return 0;
}	