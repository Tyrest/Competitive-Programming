#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (size_t i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        int ans = n;
        // MAP IS FASTER THAN HASH MAP in this case
        // seems like map is generally better at a lot of insertions/deletions
        // whereas hash map is better at a lot of lookups
        map<int, int> counts; 
        for (size_t j = 0; j < n; ++j)
        {
            int a;
            cin >> a;
            if (counts.count(a) && counts[a] > 0)
            {
                --counts[a];
                --ans;
            }
            else
            {
                ++counts[~a & 2147483647];
            }
        }

        cout << ans << '\n';
    }
}
