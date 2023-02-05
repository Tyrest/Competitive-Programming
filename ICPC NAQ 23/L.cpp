#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

ll gcd(ll a, ll b)
{
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    fast_cin();

    ll t, s;
    cin >> t >> s;

    ll spider_total = 2 * (s + 1) * s + 1;
    ll taxi_total = 2 * (t + 1) * t + 1;
    if (t > s)
    {
        taxi_total = 2 * (s + 1) * s + 1;
    }
    spider_total += 4 * (s / 3) * (s % 3 - 2);
    spider_total += 4 * 3 * (s / 3) * (s / 3 + 1) / 2;

    // s / 3 extra layers
    // if t > s, t - s - s / 3 layers are covered

    if (t > s)
    {
        ll layer_1 = s - 2;
        ll layer_2_num = min(t - s - 1, s / 3 - 1);
        ll layer_2 = layer_1 - 3 * layer_2_num;
        taxi_total += 4 * (layer_2_num + 1) * (layer_1 + layer_2) / 2;
    }

    if (taxi_total == spider_total) {
        cout << 1;
        return 0;
    }

    ll d = gcd(taxi_total, spider_total);

    cout << taxi_total / d << '/' << spider_total / d;
}