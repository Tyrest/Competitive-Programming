#include <bits/stdc++.h>
#include <math.h>
using namespace std;


typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main()
{
    fast_cin();
    ll r, s, h;

    cin >> r >> s >> h;

    float distance = 2 * r * M_PI;

    float days = distance / s / h;

    float extra = days - int(days);
    cout << extra << '\n';
    int n1 = round(1 / extra);
    extra = min(abs(1 - n1 * extra), abs(n1 * extra - 1));
    cout << extra << '\n';
    float n2 = round(1 / extra);
    extra = min(abs(1 - n2 * extra), abs(n2 * extra - 1));
    cout << extra << '\n';
    float n3 = round(1 / extra);

    cout << n1 << ' ' << n2 << ' ' << n3;
}