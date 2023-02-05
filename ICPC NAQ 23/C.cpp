#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fast_cin();

    string a, b;
    cin >> a >> b;

    int a_i = 0, b_i = 0;

    string ans;

    while (a_i < a.size() && b_i < b.size()) {
        if (a[a_i] < b[b_i]) {
            ans.push_back(a[a_i]);  
            a_i++;
        } else {
            ans.push_back(b[b_i]);
            b_i++;
        }
    }

    if (a_i < a.size()) {
        ans.append(a.substr(a_i));
    } else if (b_i < b.size()) {
        ans.append(b.substr(b_i));
    }

    cout << ans;
}