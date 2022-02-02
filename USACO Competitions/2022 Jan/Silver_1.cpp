#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, ans = 0;
    cin >> a >> b;
    if (a < b)
    {
        while (a * 2 < b)
        {
            if (b % 2)
            {
                --b;
                ++ans;
            }
            b /= 2;
            ++ans;
        }
    }
    else
    {
        while (a > b)
        {
            if (a % 2)
            {
                ++a;
                ++ans;
            }
            a /= 2;
            ++ans;
        }
    }

    ll diff = 3;
    if (a % 2)
        ++diff;
    if (b % 2)
        ++diff;

    while (b - a > diff)
    {
        diff = 3;
        if (a % 2)
        {
            ++a;
            ++ans;
        }
        if (b % 2)
        {
            --b;
            ++ans;
        }

        a /= 2;
        ++ans;
        b /= 2;
        ++ans;

        if (a % 2)
            ++diff;
        if (b % 2)
            ++diff;
    }

    cout << ans + (b - a) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}