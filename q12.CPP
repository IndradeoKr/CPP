#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter how many number you want to take" << endl;
    cin >> num;
    int arr[num];
    int arr2[num];
    int a, n = 0;
    cout << "Enter any " << num << " numbers to compare" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i <= num; i++)
    {
        arr2[i] = arr[i];
    }
    for (int i = 0; i < num - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            a = arr[i];
            arr[i + 1] = arr[i];
        }
        else
        {
            a = arr[i + 1];
        }
    }
    for (int i = 0; i < num; i++)
    {
        if (a == arr2[i])
        {
            n++;
        }
    }

      cout << "Your entered numbers are " << endl;
      for (int i = 0; i < num; i++)
      {
         cout <<" " << arr2[i];
      }
      cout << endl;

    cout << "Lagest number is " << a << endl;
    cout << "Frequency of lagest number is " << n << endl;

    return 0;
}