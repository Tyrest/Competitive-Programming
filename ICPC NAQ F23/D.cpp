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

    int n, r, w, h;
    cin >> n >> r >> w >> h;

    vector<pair<int, int>> loc(n);
    vector<int> val(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> loc[i].first >> loc[i].second >> val[i];
    }

    int sum = 0;
}