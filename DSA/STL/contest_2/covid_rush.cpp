#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int> vacant_center;
map<int, vector<int>> to_discharge;

void discharge_patients_until_day(int day)
{
    for(auto it = to_discharge.begin(); it != to_discharge.end(); it++)
    {
        int discharge_day = it->first;
        auto &centres = it->second;
        if(day < discharge_day) break;
        for(auto centre : centres)
        {
            vacant_center.insert(centre);
        }
        to_discharge.erase(it);
    }
}

int get_vacant_centre(int patient_index)
{
    auto available_center_it = vacant_center.lower_bound(patient_index % m);
    if(available_center_it == vacant_center.end())
        available_center_it = vacant_center.begin();
    return *available_center_it;
}

int main()
{
    cout << "Enter number of patient and number of center\n";
    cin >> n >> m;
    vector<pair<int,int>> timings(n);
    vector<int> treated_count(m,0);
    for(int i = 0; i < n; i++)
    {
        cin >> timings[i].first;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> timings[i].second;
    }
    sort(timings.begin(), timings.end());
    for(int i = 0; i < m; i++)
    {
        vacant_center.insert(i);
    }
    for(auto &timing : timings)
    {
        int arrival_day = timing.first;
        int treatment_days = timing.second;
        discharge_patients_until_day(arrival_day);
        if(vacant_center.size() == 0) continue;
        int patient_index = &timing - &timings[0];
        int available_centre = get_vacant_centre(patient_index);
        to_discharge[arrival_day+treatment_days].push_back(available_centre);
        treated_count[available_centre]++;
        vacant_center.erase(available_centre);
    }
    for(int i = 0; i < m; i++)
    {
        cout << treated_count[i] << " ";
    }
    cout << endl;
    return 0;
}