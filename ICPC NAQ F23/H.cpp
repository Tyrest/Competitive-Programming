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

    ll n, k, p;
    cin >> n >> k >> p;

    set<ll> factors;

    for (ll i = 1; i <= sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            if (i <= k && n / i <= p)
                factors.insert(i);
            if (n / i <= k && i <= p)
                factors.insert(n / i);
        }
    }

    cout << factors.size() << endl;
    for (auto x : factors)
        cout << x << endl;
}