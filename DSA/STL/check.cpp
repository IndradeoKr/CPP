#include <bits/stdc++.h>
using namespace std;
int main()
{
	unordered_multiset<int> s = {1,2,3,4};
	unordered_multiset<int> s2 = {5,6,7,8};
	unordered_multiset<int> s3 = s;
	s.clear();
	set_union(s3.begin(), s3.end(),s2.begin(), s2.end(),inserter(s, s.begin()));
	for(auto it:s) cout << it << " ";
	return 0;
}