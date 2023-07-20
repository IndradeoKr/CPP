#include<bits/stdc++.h>
using namespace std;

//if multiple palindromic subsequence is possible than return subsquence with minimum starting index;
string longestPalin (string s) {
        int start = 0, end = 0;
        int low, high;
        
        for(int i = 0 ; i < s.size(); i++)
        {
            //even part
            low = i-1;
            high = i;
            while(low >= 0 && high < s.size() && s[low] == s[high])
            {
                if(high-low+1 > end)
                {
                    end = high-low+1;
                    start = low;
                }
                low--;
                high++;
            }
            
            //odd part
            low = i-1;
            high = i+1;
            while(low >= 0 && high < s.size() && s[low] == s[high])
            {
                if(high - low + 1 > end)
                {
                    end = high - low + 1;
                    start = low;
                }
                low--;
                high++;
            }
        }
        if(end == 0) return s.substr(start,1);
        return s.substr(start,end);
    }