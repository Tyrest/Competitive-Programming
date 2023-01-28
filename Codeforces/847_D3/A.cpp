#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N;
    cin >> N;

    string pi = "3141592653589793238462643383279";
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        int ans = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == pi[j])
                ans++;
            else
                break;
        }
        cout << ans << '\n';
    }
}