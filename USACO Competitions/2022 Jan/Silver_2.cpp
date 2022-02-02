#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N;
    cin >> N;
    list<pair<int, int>> h_stk;
    int h;
    ll ans = 0;
    list<pair<int, int>>::iterator itr;
    for (int i = 0; i < N; i++)
    {
        cin >> h;
        itr = h_stk.begin();
        while (itr != h_stk.end() && (*itr).first < h)
        {
            ans += i - (*itr).second + 1;
            // cout << i - (*itr).second + 1 << ' ';
            ++itr;
        }
        // cout << ": ";
        h_stk.insert(itr, make_pair(h, i));
        h_stk.erase(h_stk.begin(), --itr);
        itr = h_stk.begin();
        if (h_stk.size() > 1)
            ans += i - (*(++itr)).second + 1;
        // for (itr = h_stk.begin(); itr != h_stk.end(); ++itr)
        //     cout << (*itr).first << ',' << (*itr).second << ' ';
        // cout << ": " << ans << '\n';
    }

    cout << ans << '\n';
}

// int i = 0, j;

// while (i + 2 < N)
// {
//     j = i + 2;
//     ll max = h[i + 1];
//     while (j < N && max < h[i])
//     {
//         if (max < h[j])
//         {
//             max = h[j];
//             ans += j - i + 1;
//         }
//         ++j;
//     }
//     ++i;
// }

// cout << ans + (N - 1) * 2 << '\n';