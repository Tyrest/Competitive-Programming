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
    int n;
    cin >> n;
    vector<vector<int>> arr = vector<vector<int>>(n, vector<int>(n, 0));

    int totalFlights = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != -1)
            {
                totalFlights++;
            }
        }
    }
    cout << totalFlights << '\n';
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != -1)
            {
                cout << i + 1 << ' ' << j + 1 << ' ' << arr[i][j] << '\n';
            }
        }
    }
}