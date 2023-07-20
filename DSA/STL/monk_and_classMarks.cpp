#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of maps\n";
    cin >> n;
    map<int, multiset<string>> m;
    for(int i = 0; i < n; i++)
    {
        int num;
        cout << "Enter name and number\n";
        string str;
        cin >> str >> num;
        m[-1*num].insert(str);// -1 is used to stored maximum at top.
    }
    cout << endl;
    for(auto &marks_and_student_pair : m)
    {
        auto &students = (marks_and_student_pair).second;
        int marks = (marks_and_student_pair).first;
        for(auto &student : students)
        {
            cout << student << " " << -1*marks << endl;
        }
    }
    return 0;
}