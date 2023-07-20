#include<bits/stdc++.h>
using namespace std;
/*
try to think of finding median.
suppose.
arr[3,2,5,1]
cost[1,1,1,1]
then we just have to find median without thiking of its cost

now we have
arr[3,2,5,1]
cost[3,4,2,1]

can we write this as 
arr[3,3,3,2,2,2,2,5,5,1]
cost[1,1,1,1,1,1,1,1,1,1]
again after sorting we can find median(using frequency)
*/

// finding median
class Solution {
    using ll = long long;
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> v;
        ll total = 0;
        for(int i = 0; i < n; i++)
        {
            v.push_back({nums[i],cost[i]});
            total += cost[i];
        }

        sort(v.begin(),v.end());
        ll sum = 0;
        int median = v[0].first, j = 0;
        while(sum < (total+1)/2 && j < n)
        {
            sum += v[j].second;
            median = v[j].first;
            j++;
        }
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += (abs(median - (ll)v[i].first)*(ll)v[i].second);
        }
        return sum;
    }
};

//prefix sum
//read editorial
class Solution {
    using ll = long long;
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        vector<ll> prefix;
        ll t = 0;
        for(auto it:v)
        {
            t += it.second;
            prefix.push_back(t);
        }
        ll total = 0;
        for(int i = 0; i < n; i++)
        {
            total += (ll)(v[i].second*(ll)(v[i].first-v[0].first));
        }
        ll ans = total;
        for(int i = 1; i < n; i++)
        {
            ll gap = v[i].first - v[i-1].first;
            total += (ll)prefix[i-1]*gap;
            total -= (ll)(prefix[n-1]-prefix[i-1])*gap;
            ans = min(ans,total);
        }
        return ans;
    }
};

//bianry search(ternary search)
class Solution {
    using ll = long long;
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = INT_MAX, h = INT_MIN;
        for(auto it:nums)
        {
            l = min(l,it);
            h = max(h,it);
        }
        ll ans = get(nums,cost,nums[0]);
        while(l < h)
        {
            ll mid = (h-l)/2 + l;
            ll cost1 = get(nums,cost,mid);
            ll cost2 = get(nums,cost,mid+1);
            ans = min(cost1,cost2);
            if(cost1 < cost2) h = mid;
            else l = mid+1;
        }
        return ans;

    }
    ll get(vector<int> &nums, vector<int> &cost, int base)
    {
        ll res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            res += abs((ll)base-nums[i])*(ll)cost[i];
        }
        return res;
    }
};

int main()
{

    return 0;
}