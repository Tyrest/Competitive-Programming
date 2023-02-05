#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    vector<ll> power(n);

    for (int i = 0; i < n; i++)
    {
        cin >> power[i];
    }

    sort(power.begin(), power.end());

    // vector<ll> prefix;
    // prefix.push_back(power[0]);
    // for (ll i = 1; i < power.size(); i++)
    // {
    //     prefix.push_back(prefix[i - 1] + power[i]);
    // }

    ll prev_sum = power[power.size() - 1];
    ll sum = 0;
    int split = power.size() - 1;
    for (int i = power.size() - 2; i >= 0; i--)
    {
        sum += power[i];
        if (sum >= prev_sum) {
            // cout << prev_sum << " <= " << sum << '\n';
            split = i;
            prev_sum += sum;
            sum = 0;
        }
    }

    cout << power.size() - split;
}