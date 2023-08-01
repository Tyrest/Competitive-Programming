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
        unordered_map<char, int> bin;
        int n;
        cin >> n;
        string s;
        cin >> s;

        int b = 0;
        bool works = true;
        for (auto c : s)
        {
            if (bin.find(c) == bin.end())
            {
                bin[c] = b;
            }
            else
            {
                if (bin[c] != b)
                {
                    works = false;
                    break;
                }
            }
            b = 1 - b;
        }

        if (works)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}