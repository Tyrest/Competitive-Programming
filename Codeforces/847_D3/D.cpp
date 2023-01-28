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

        map<int, int> counts;
        int a;
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            counts[a] += 1;
        }

        int ans = 0;
        int prev_size = counts.begin()->first - 1;
        int prev_count = counts.begin()->second;
        for (auto x : counts)
        {
            if (prev_size != x.first - 1)
                ans += prev_count;
            else if (prev_count > x.second)
                ans += prev_count - x.second;
            prev_size = x.first;
            prev_count = x.second;
        }

        cout << ans + prev_count << '\n';
    }
}