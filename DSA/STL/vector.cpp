#include <bits/stdc++.h>
using namespace std;
//for online plate form :-

//for local declaration of array and vector, elements must be <= 10^5.
//for global declaration of array and vector, elements must be <= 10^7.
void printVec(vector <int> v)
{
    cout << "size: " << v.size() << endl;
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
vector<int> x(101,-1);
int main()
{
    vector <int> v;
    int n;
    cout << "Enter the size of vector" << endl;
    cin >> n;
    cout << "Enter elements" << endl;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        //printVec(v);
        v.push_back(x); // It is used to put value at the end.
    }
    string s;
    s[0] = {1};
    cout << s;
    sort(v.begin(),v.end());// sort in increasing order.
    printVec(v);
    sort(v.rbegin(),v.rend());// sort in decreasing order.
    printVec(v);
    /* vector <int> v(5); Every elements contain zero.
       vector <int> v(5, 3); Every elements contain 3.
       vector <int> v; Empty vector.
       vector <int> v1 = v; O(n). 
       vector<int>::iterator iter = v.begin();// used to insert the element in vector at begging.
        vec1.insert(iter, 566);
        display(v);

    //it is more suitable to used than v[3];
    cout << v.at(3);// it will give element at position 3.
    cout << v.capacity(); // used to show the capacity of vector.*/
    return 0;
}