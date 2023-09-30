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

    int n, a, b;
    cin >> n >> a >> b;

    bool min_sat = false;
    bool max_sat = false;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == a)
            min_sat = true;
        if (x == b)
            max_sat = true;
        if (x < a || x > b)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    if (!min_sat && !max_sat)
    {
        cout << -1 << endl;
    }
    else if (min_sat && max_sat)
    {
        for (int i = a; i <= b; i++)
        {
            cout << i << "\n";
        }
    }
    else if (min_sat)
    {
        cout << b << endl;
    }
    else
    {
        cout << a << endl;
    }
}