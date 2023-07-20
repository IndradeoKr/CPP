#include <bits/stdc++.h>
using namespace std;
template <typename T, typename v>
class Pair
{
    T x;
    v y;

    public:

    void setX(T x)
    {
        this-> x = x;
    }
    T getX()
    {
        return x;
    }

    void setY(v y)
    {
        this-> y = y;
    }
    v getY()
    {
        return y;
    }
};