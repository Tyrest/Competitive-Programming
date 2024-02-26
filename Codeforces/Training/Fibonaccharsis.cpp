#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int fib(ll n, ll k, ll m) {
    for (int i = 0; i < k - 2; ++i) {
        m = n - m;
        n = n - m;
        if (m < 0) {
            return 1;
        }
        else if (n < m) {
            return 1 + i % 2;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        ll n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "1\n";
        }
        else if (k == 2) {
            cout << n << '\n';
        }

        // the number before n must be between (n + 1) // 2 and n
        // binary search for the lowest number in the range that has that length fib will return 1 if too low
        // binary search for the highest number in the range that has that length fib will return 2 if too high
        // take difference as the answer
        ll lo = (n + 1) / 2;
        ll hi = n;
        ll mid = 0;

        int res;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            res = fib(n, k, mid);
            if (res != 1) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        ll lowest;
        if (res != 0)
            lowest = mid + 1;
        else
            lowest = mid;

        lo = (n + 1) / 2;
        hi = n;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            res = fib(n, k, mid);
            if (res != 2) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        ll highest;
        if (res != 0)
            highest = mid - 1;
        else
            highest = mid;

        if (highest - lowest >= 0)
            cout << highest - lowest + 1 << "\n";
        else
            cout << "0\n";
    }
}