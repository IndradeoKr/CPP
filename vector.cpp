#include <iostream>
#include <vector>
using namespace std;

template <class T>
void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec1;        // zero length integer vector
    vector<char> vec2(4);    // 4-element character vector
    vector<char> vec3(vec2); // 4-element character vector from vec2
    vector<int> vec4(6, 3);  // 6-element vector of 3s
    int element, size;

    cout << "Enter the size of your vector" << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter an element to add to this vector: ";
        cin >> element;
        vec1.push_back(element);
    }

    display(vec1);

    vec1.pop_back();// it is used to delete the element from the back.
    display(vec1);

    vector<int>::iterator iter = vec1.begin();// used to insert the element in vector at begging.
    vec1.insert(iter, 566);
    display(vec1);

    //it is more suitable to used than vec1[3];
    cout << vec1.at(3);// it will give element at position 3.
    return 0;
}
