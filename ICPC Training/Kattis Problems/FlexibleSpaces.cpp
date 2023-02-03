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

    int w, p;
    cin >> w >> p;

    vector<int> parts = {0};
    int l;
    for (int i = 0; i < p; i++) {
        cin >> l;
        parts.push_back(l);
    }
    parts.push_back(w);

    set<int> spaces;
    for (int i = 0; i < parts.size() - 1; i++) {
        for (int j = i + 1; j < parts.size(); j++) {
            spaces.insert(parts[j] - parts[i]);
        }
    }

    for (auto s : spaces) {
        cout << s << ' ';
    }
}