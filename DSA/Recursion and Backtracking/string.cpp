#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s2;
    s2 = "def";

    cout << "Enter a string" << endl;
    getline(cin, s); // this is used to take input a string including space.
    cout << s << endl;

    string *sp = new string;// string pointer.
    *sp = "abc";

    cout << sp << endl;// printing address of string.
    cout << *sp << endl;//printing vlaue stored at that address.

    string s3 = s + s2;// this is used to join to string into one string but thier is no space between these strings.

    cout << s3 << endl;

    s2 += s;// this is used to merge string s into s2.

    cout << "After merging two string" << endl << s2 << endl;
    cout << "size of string: " << s2.size() << endl;//this is used to find the size of a string and also s.lenght() will do same.
    cout << s2.substr(3) << endl;//this gives all character after 3rd character.
    cout << s2.substr(3, 3) << endl;//this gives 3 character after 3rd character.//syntax :: string_name.substr(start, length), lenght is optinal and gives all character after start + 1.
    cout << s2.find("abc") << endl;//this gives the index of first a. 
    return 0;
}