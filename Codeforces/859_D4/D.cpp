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
        int n, q;
        cin >> n >> q;

        vector<ll> a(n + 1);
        a[0] = 0;
        ll sum = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> a[j + 1];
            sum += a[j + 1];
            a[j + 1] = sum;
            // cout << a[j + 1] << '\n';
        }

        for (int j = 0; j < q; j++)
        {
            ll l, r, k;
            cin >> l >> r >> k;

            // cout << a[l - 1] + (k * (r - l + 1)) + a[a.size() - 1] - a[r] << '\n';

            if ((a[l - 1] + ((k % 2) * ((r - l + 1) % 2)) + a[a.size() - 1] - a[r]) % 2 == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}