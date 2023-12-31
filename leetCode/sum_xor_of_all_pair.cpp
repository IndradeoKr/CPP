// Given an array of N integers, find the sum of xor of all pairs of numbers in the array.

// Input:
// The first line of the input contains a single integer T denoting the number of test cases. The first line of each test case contains N. followed by n separate integers. 

// Output:
// For each test case, output a single integer i.e sum of xor of all pairs of numbers in the array.

// Constraints
// 1 ≤ T ≤ 1000
// 2 ≤ N ≤ 10^5
// 1 ≤ A[i] ≤ 10^5

// Example:
// Input :
// 2
// 3
// 7 3 5
// 4
// 5 9 7 6
// Output :
// 12
// 47

// Explanation :

// Testcase 1: all possible pairs and there Xor Value : ( 3 ^ 5 = 6 ) + (7 ^ 3 = 4) + ( 7 ^ 5 = 2 ) : 6 + 4 + 2 = 12
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    int x=0;
	    for(int i=0;i<n;i++)
	    {
	    cin>>arr[i];
	   }
	   
	  unsigned long long  int ans=0;
	   for(int i=0;i<32;i++)
	   {
	      unsigned long long  count=0,count1=0;
	       for(int j=0;j<n;j++)
	       {
	           if(arr[j]&(1<<i))
	           {
	               count++;
	           }
	           else
	           count1++;
	       }
	       ans=(unsigned long long  int)ans+(1<<i)*count*count1;
	   }
	 cout<<ans<<endl;  
	}
	return 0;
}