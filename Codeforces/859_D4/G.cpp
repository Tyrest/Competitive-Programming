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

        vector<ll> a(n);

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }

        sort(a.begin(), a.end());

        ll max = 1;
        bool works = true;
        if (a[0] != 1)
        {
            works = false;
        }
        else
        {
            for (int j = 1; j < a.size(); j++)
            {
                if (a[j] > max)
                {
                    works = false;
                    break;
                }
                max += a[j];
            }
        }

        if (works)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}