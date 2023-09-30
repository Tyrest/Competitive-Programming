#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int find_team(unordered_set<int> &used, int i, vector<pair<int, int>> &ranks) {
    vector<int> teammates;
    for (int j = ranks[i].first - 1; j < ranks[i].second; j++)
    {
        if (i != j && used.find(j) == used.end() && i + 1 >= ranks[j].first && i + 1 <= ranks[j].second)
        {
            teammates.push_back(j);
        }
    }

    // for (auto x: teammates)
    //     cout << x << " ";
    // cout << endl;

    for (int j = 0; j < teammates.size(); j++)
    {
        for (int k = j + 1; k < teammates.size(); k++)
        {
            if (teammates[j] + 1 >= ranks[teammates[k]].first && teammates[j] + 1 <= ranks[teammates[k]].second &&
                teammates[k] + 1 >= ranks[teammates[j]].first && teammates[k] + 1 <= ranks[teammates[j]].second)
            {
                used.insert(i);
                used.insert(teammates[j]);
                used.insert(teammates[k]);
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    fast_cin();

    int n;
    cin >> n;

    vector<pair<int, int>> ranks(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ranks[i].first >> ranks[i].second;
    }

    unordered_set<int> used;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (used.find(i) != used.end())
            continue;
        
        count += find_team(used, i, ranks);
        // cout << i << " " << count << endl;
        // // for (auto x : used)
        // //     cout << x << " ";
        // // cout << endl;
    }

    cout << count << endl;
}