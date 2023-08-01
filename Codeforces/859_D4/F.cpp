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
        int n, m, i1, j1, i2, j2;
        string d_str;
        cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d_str;

        pair<int, int> cur;
        bool UR;
        if (d_str == "DL" || d_str == "UR")
        {
            UR = true;
        }
        else
        {
            UR = false;
        }

        if (UR)
        {
            if (i1 + j1 == i2 + j2 &&
                ((d_str == "DL" && i2 >= i1) ||
                 (d_str == "UR" && i2 <= i1)))
            {
                cout << "0\n";
                continue;
            }
        }
        else if (!UR)
        {

            if (i1 - j1 == i2 - j2 &&
                ((d_str == "DR" && i2 >= i1) ||
                 (d_str == "UL" && i2 <= i1)))
            {
                cout << "0\n";
                continue;
            }
        }
    }
}