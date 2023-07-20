#include <iostream>
using namespace std;
 

int linearSearch_recursive(int arr[],int size ,int element)
{  
    if(size == 0)
        return -1;
    if(arr[0] == element)
        return 0;
    int ans = linearSearch_recursive(arr+1, size-1, element);
    if(ans == -1)
        return -1;
    return ans + 1;
}
 
// Driver Code
int main()
{   
    int size;
    cin>>size; //size of array
    int arr[size];
    
    for(int i=0;i<size;i++){
       cin>>arr[i]; // elemnents in the array
    }
   
   int element; // element to be searched
    cin>>element;
 
    int result = linearSearch_recursive(arr,size,element);
    (result == -1)
        ? cout << "-1"
        : cout << "Element is present at index " << result;
    return 0;
}