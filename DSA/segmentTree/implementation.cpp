#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int a[N+5], seg[4*N+5], lazy[4*N+5];

/* This code is to find max */
void build(int ind, int low, int high)
{
    if(low == high)
    {
        seg[ind] = a[low];
        return;
    }

    int mid = low + (high-low)/2;

    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    /* Backtracking will store the max value from left and right to the node */
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind, int low, int high, int l, int r)//(ind,low,high,left,right)
{
    /* ***completely lies inside the range***
       example:- query(left(l) = 2, right(r) = 5)(this is given in the question)
       low = 2, high = 5;
       low = 3, high = 4;

       ***does not lies inside the range***
       low = 0, high = 1;
       low = 6, high = 8;

       ***overlaping condition**
       low = 0, high = 2;
       low = 3 ,high = 6;
       low = 3 ,high = 7;

       *************************************************
       ***Note:- low and high are index of seg array;***
       *************************************************
    */

    if(l <= low && high <= r)//completely lies inside the array
    {
        return seg[ind];
    }

    if(high < l || low > r)//does not lies inside the loop
    {
        return INT_MIN; //because we are finding the maxmium value;
    }

    //overlaping 
    int mid = low + (high-low)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return max(left,right);
}

void pointUpdate(int ind, int low, int high, int node, int val)
{
    if(low == high)
    {
        seg[ind] += val;
    }
    else
    {
        int mid = low + (high-low)/2;
        if(low <= node && node <= mid)
        {
            pointUpdate(2*ind+1,low,mid,node,val);
        }
        else
        {
            pointUpdate(2*ind+2,mid+1,high,node,val);
        }
        seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
    }
}

void rangeUpadate(int ind, int low, int high, int l, int r, int val)
{
    if(lazy[ind] != 0)
    {
        seg[ind] += (high - low + 1) * lazy[ind];
        if(low != high)
        {
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if(high < l || low > r || low > high) return;

    if(l <= low && high <= r)
    {
        seg[ind] += (high - low + 1) * val;
        if(low != high)
        {
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        return;
    }

    int mid = low + (high - low)/2;
    rangeUpadate(2*ind+1, low, mid, l, r, val);
    rangeUpadate(2*ind+2,mid+1,high,l,r,val);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(0,0,n-1);//(index,low,high);
    // for(int i = 0; i < 4*n; i++) cout << seg[i] << " ";
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << query(0,0,n-1,l,r) << endl;//(index,low,high,l,r);
        int p,val;
        cout << "Enter a point where you want to add number and how much: ";
        cin >> p >> val;
        pointUpdate(0,0,n-1,p,val);
    }
}