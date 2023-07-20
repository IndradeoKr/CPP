#include<iostream>
using namespace std;
 
double sum_of_digits(int n){
    int ans;
    if(n == 0)
        return 0;
    if(n > 0)
        ans = n%10;
    int sum = sum_of_digits(n/10);
    return sum + ans;
}

//Driver Code
int main()
{   
    double n;
    cin>>n;
    cout<<sum_of_digits(n);
    return 0;
}