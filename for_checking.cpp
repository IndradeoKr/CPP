#include <bits/stdc++.h>
using namespace std;
void f(int b, int &a, int *c)
{
  *c = *c + 3;
  a  = 14;
  // b = b + 1;
  cout << b << " " << " " << *c << endl;
}
int main()
{
  int a, *c;
  int b = 10;
  a = 10;
  c = &b;
  cout << a << endl;
  f(b, a, c);
  cout << a << endl;
  return 0;
}