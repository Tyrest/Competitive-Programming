#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> places(n - 1, pair<int, int>(-1, -1));
        int p;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n - 1; k++)
            {
                cin >> p;
                if (places[k].first == -1)
                    places[k].first = p;
                else if (places[k].first != p)
                    places[k].second = p;
            }
        }

        for (int j = 0; j < n - 2; j++)
        {
            if (places[j].first != places[j + 1].first && places[j].first != places[j + 1].second)
                cout << places[j].first << ' ';
            else
                cout << places[j].second << ' ';
        }

        // cout << " (" << places[n - 2].first << ' ' << places[n - 2].second << ") ";

        if (places[n - 2].first != places[n - 3].first && places[n - 2].first != places[n - 3].second)
            cout << places[n - 2].second << ' ' << places[n - 2].first << '\n';
        else
            cout << places[n - 2].first << ' ' << places[n - 2].second << '\n';
    }
}