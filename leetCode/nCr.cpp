#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int t = m+n-2;
        int r = m-1;
        long long int res = 1;
        //tCr
        for(int i = 1; i <= r; i++)
        {
            res = res * (long long int)(t-r+i)/i;
        }
        return res;
    }
};

int main()
{

}