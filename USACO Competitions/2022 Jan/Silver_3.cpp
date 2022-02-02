#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> c(N);
    vector<bool> d(N, false);
    vector<int> f(M, 0);
    vector<int> s(M, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> c[i].first >> c[i].second;
        ++f[c[i].first];
        ++s[c[i].second];
    }

    list<int> ans;

    bool repeat = true;
    int target = 1;
    while (repeat)
    {
        repeat = true;
        for (int i = 0; i < N; i++)
        {
            if (c[i].first == target || c[i].second == target)
        }
        ++target;
    }
}