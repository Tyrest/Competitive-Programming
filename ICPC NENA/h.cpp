#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int dijkstras(unordered_map<int, unordered_map<int, int>> &city, int n, int a, int b)
{
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, a));
    unordered_map<int, pair<int, unordered_set<int>>> distances;
    distances[a] = make_pair(0, unordered_set<int>());
    while (!q.empty())
    {
        int w = q.top().first;
        int v = q.top().second;
        // cout << v << '\n';
        q.pop();
        if (distances[v].first < w)
            continue;
        for (auto edge : city[v])
        {
            // cout << edge.first << ' ' << edge.second << ' ' << w + edge.second << '\n';
            if (distances.find(edge.first) == distances.end() || distances[edge.first].first > w + edge.second)
            {
                unordered_set<int> tmp = distances[v].second;
                tmp.insert((min(v, edge.first) - 1) * n + max(v, edge.first) - 1);
                distances[edge.first] = make_pair(w + edge.second, tmp);
                q.push(make_pair(w + edge.second, edge.first));
            }
            else if (distances[edge.first].first == w + edge.second)
            {
                // cout << "HERE!\n";
                for (auto e : distances[v].second)
                {
                    distances[edge.first].second.insert(e);
                }
                distances[edge.first].second.insert((min(v, edge.first) - 1) * n + max(v, edge.first) - 1);
            }
        }
    }

    // cout << '\n';
    // for (auto d : distances)
    // {
    //     cout << d.first << ' ' << d.second.first << '\n';
    // }
    // cout << '\n';

    int ans = 0;
    for (auto e : distances[b].second)
    {
        // cout << e / n << ' ' << e % n << '\n';
        ans += city[(e / n) + 1][(e % n) + 1];
    }

    return ans;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    unordered_map<int, unordered_map<int, int>> city;

    int i1, i2, l;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> i1 >> i2 >> l;
        city[i1][i2] = l;
        city[i2][i1] = l;
        ans += l;
    }

    int d = dijkstras(city, n, a, b);

    cout << ans - d;
}