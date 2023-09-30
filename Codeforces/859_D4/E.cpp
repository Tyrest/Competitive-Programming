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

        vector<int> a(n + 1);
        a[0] = 0;
        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> a[j + 1];
            sum += a[j + 1];
            a[j + 1] = sum;
        }

        int low = 0;
        int mid = (a.size() - 1) / 2;
        int hi = a.size() - 1;
        while (low < hi)
        {
            cout << "? " << mid + 1 - low;
            for (int j = low; j <= mid; j++)
            {
                cout << ' ' << j + 1;
            }
            cout << '\n';
            cout.flush();

            int sum;
            cin >> sum;

            int low_sum = a[mid + 1] - a[low];
            if (low_sum != sum)
            {
                hi = mid;
            }
            else
            {
                low = mid + 1;
            }
            mid = (low + hi) / 2;
        }
        cout << "! " << mid + 1 << '\n';
        cout.flush();
    }
}