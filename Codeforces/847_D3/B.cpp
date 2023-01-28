#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n, s, r;
        cin >> n >> s >> r;

        int max = s - r;
        cout << max;
        n -= 1;
        while (n--)
        {
            if (r - max <= n)
            {
                cout << ' ' << r - n;
                r -= r - n;
            }
            else
            {
                cout << ' ' << max;
                r -= max;
            }
        }
        cout << '\n';
    }
}