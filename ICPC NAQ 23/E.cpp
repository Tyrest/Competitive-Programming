#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const vector<pair<int, int>> dirs = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};

int flood_fill(const vector<string> &maze, unordered_set<int> &discovered, pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);

    int count = 0;
    bool entrance = false;
    discovered.insert(start.first * maze[0].size() + start.second);

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        if (maze[curr.first][curr.second] == '.')
        {
            // cout << curr.first << ' ' << curr.second << '\n';
            count++;
        }

        for (int i = 0; i < dirs.size(); i++)
        {
            pair<int, int> next = make_pair(curr.first + dirs[i].first, curr.second + dirs[i].second);

            if (discovered.find(next.first * maze[0].size() + next.second) == discovered.end() && maze[next.first][next.second] != 'X')
            {
                if (maze[next.first][next.second] >= 'A' && maze[next.first][next.second] <= 'W')
                {
                    // cout << maze[next.first][next.second] << '\n';
                    entrance = true;
                }
                else
                {
                    q.push(next);
                    discovered.insert(next.first * maze[0].size() + next.second);
                }
            }
        }
    }

    // cout << "Count: " << count << '\n';

    if (entrance)
    {
        if (count > 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return count;
    }
}

int main()
{
    fast_cin();

    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    getline(cin, maze[0]);
    for (int i = 0; i < n; i++)
    {
        getline(cin, maze[i]);
    }
    

    unordered_set<int> discovered;

    int entrances = 0;
    int unreachable = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '.' && discovered.find(i * m + j) == discovered.end()) {
                // cout << "Point: " << i << ' ' << j << '\n';

                int result = flood_fill(maze, discovered, make_pair(i, j));
                if (result < 0) {
                    entrances++;
                } else {
                    unreachable += result;
                }
            }
        }
    }

    cout << entrances << ' ' << unreachable;
}