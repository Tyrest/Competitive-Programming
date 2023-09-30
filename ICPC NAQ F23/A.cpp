#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main()
{
    int n, k, c;
    cin >> n >> k >> c;

    vector<int> t(n);
    vector<int> s(n);

    for (int i = 0; i < n; i++)
        cin >> t[i] >> s[i];
    
    set<int> teams;
    map<int, int> school_team_count;
    
    for (int i = 0; i < n; i++)
    {
        if (school_team_count[s[i]] < c)
        {
            teams.insert(t[i]);
            school_team_count[s[i]]++;
        }
        if (teams.size() >= k)
            break;
    }

    if (teams.size() < k)
    {
        for (int i = 0; i < n; i++)
        {
            if (teams.find(t[i]) == teams.end())
            {
                teams.insert(t[i]);
            }
            if (teams.size() >= k)
                break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (teams.find(t[i]) != teams.end())
            cout << t[i] << "\n";
    }
}