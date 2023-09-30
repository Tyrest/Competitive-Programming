#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main()
{
    int n, lph;
    cin >> n >> lph;

    vector<int> loc(n);
    for (int i = 0; i < n; i++)
        cin >> loc[i];

    sort(loc.begin(), loc.end());

    int sum = 0;
    int num = 0;
    for (int i = 0; i < n; i++)
    {   
        if (sum + loc[i] > lph * 5)
        {
            cout << num << endl;
            return 0;
        }
        sum += loc[i];
        num++;
    }
    cout << num << endl;
}