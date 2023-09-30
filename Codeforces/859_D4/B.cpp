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
        int n;
        cin >> n;
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            if (a % 2 == 1)
            {
                a = -a;
            }
            sum += a;
        }
        if (sum > 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}