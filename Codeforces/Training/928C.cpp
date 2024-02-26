#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        ll temp = n;
        ll ans = 0;
        ll factor = 1;
        while (temp) {
            ans += 45 * (temp / 10) * factor;
            // cout << ans << '\n';
            ans += (temp % 10 - 1) * (temp % 10) / 2 * factor;
            // cout << ans << '\n';
            ans += (temp % 10) * (n % factor + 1);
            // cout << ans << '\n';
            temp /= 10;
            factor *= 10;
        }
        cout << ans << '\n';
    }
    
}
