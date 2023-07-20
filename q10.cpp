#include <iostream>
using namespace std;
void notecount(int amount)
{
    int typesn[10] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int numnotes[10] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        if(amount >= typesn[i])
        {
            numnotes[i] = amount / typesn[i];
            amount = amount - numnotes[i]*typesn[i]; 
        }
    }
    for(int i = 0; i < 10; i++)
    {
        if ( numnotes[i] != 0)
        {
            cout << typesn[i] << " = " <<  numnotes[i] << endl;
        }

    }
}
int main()
{
    int n;
    cout << "Enter the amount"<< endl;
    cin >> n;
    notecount(n);
    
    return 0;
}