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

    ll t;
    cin >> t;
    string line;
    getline(cin, line);
    for (int i = 0; i < t; i++)
    {
        getline(cin, line);
        if (line.substr(0, 10) == "Simon says") {
            cout << line.substr(10) << '\n';
        }
    }
}