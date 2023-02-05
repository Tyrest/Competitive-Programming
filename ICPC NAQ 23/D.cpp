#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fast_cin();

    int n, m;
    cin >> n >> m;

    vector<int> rungs(m);
    for (int i = 0; i < m; i++)
    {
        cin >> rungs[i];
    }
    
    for (int i = 1; i < n + 1; i++) {
        int curr = i;
        for (int j = rungs.size() - 1; j >= 0; j--)
        {
            if (rungs[j] == curr) {
                curr++;
            } else if (rungs[j] == curr - 1) {
                curr--;
            }
        }
        cout << curr << '\n';
    }
}