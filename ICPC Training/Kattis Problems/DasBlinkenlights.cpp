#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    fast_cin();

    int p, q, s;
    cin >> p >> q >> s;
    if (p < q) {
        swap(p, q);
    }

    if (p * q / gcd(p, q) <= s) {
        cout << "yes";
    } else {
        cout << "no";
    }
}