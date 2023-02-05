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

    int n, s, k;
    cin >> n >> s >> k;

    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pq.push(temp << 1);
    }

    int ans = 0;

    int l_anchor = -k;
    int l_size = 0;
    int c_anchor = pq.top();
    pq.pop();
    while (!pq.empty())
    {
        // cout << c_anchor << '\n';
        int l_space = c_anchor - (l_anchor + l_size);

        int n_anchor = pq.top();
        pq.pop();

        int r_space = (n_anchor - s) - c_anchor;

        if (l_space < s || r_space < s) {
            cout << -1;
            return 0;
        }

        int size = min(l_space, r_space);
        size = min(size, k);
        // cout << size << '\n';
        ans += size;

        l_anchor = c_anchor;
        l_size = size;
        c_anchor = n_anchor;
    }

    int l_space = c_anchor - (l_anchor + l_size);

    ans += min(l_space, k);

    cout << ans;
}