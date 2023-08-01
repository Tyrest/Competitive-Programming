#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main()
{
    fast_cin();

    string dna;
    cin >> dna;
    int m;
    cin >> m;
    vector<pair<int, int>> arr = vector<pair<int, int>>(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<int> sums = {0, 0, 0, 0};
    vector<vector<int>> prefix;
    prefix.push_back(sums);

    for (int i = 0; i < dna.size(); i++)
    {
        int ind;
        if (dna[i] == 'A')
        {
            ind = 0;
        }
        else if (dna[i] == 'T')
        {
            ind = 1;
        }
        else if (dna[i] == 'G')
        {
            ind = 2;
        }
        else if (dna[i] == 'C')
        {
            ind = 3;
        }
        sums[ind]++;
        prefix.push_back(sums);
    }

    for (int i = 0; i < m; i++)
    {
        vector<int> prev = {prefix[arr[i].second][0] - prefix[arr[i].first - 1][0], prefix[arr[i].second][1] - prefix[arr[i].first - 1][1], prefix[arr[i].second][2] - prefix[arr[i].first - 1][2], prefix[arr[i].second][3] - prefix[arr[i].first - 1][3]};
        vector<int> bases = {0, 1, 2, 3};
        int max = -2;
        unordered_set<int> maxes;
        while (max != -1)
        {
            max = -1;
            for (size_t i = 0; i < 4; i++)
            {
                if (max < prev[i] && maxes.find(prev[i]) == maxes.end())
                {
                    max = prev[i];
                }
            }
            maxes.insert(max);
            for (size_t i = 0; i < 4; i++)
            {
                if (prev[i] == max)
                {
                    if (i == 0)
                    {
                        cout << 'A';
                    }
                    else if (i == 1)
                    {
                        cout << 'T';
                    }
                    else if (i == 2)
                    {
                        cout << 'G';
                    }
                    else if (i == 3)
                    {
                        cout << 'C';
                    }
                }
            }
        }
        cout << '\n';
    }
}