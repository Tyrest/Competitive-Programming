#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int increment_pivot(int pivot, bool forward) {
    if (forward)
        pivot++;
    else
        pivot--;
    
    if (pivot < 0)
        return 26 + pivot;
    return pivot % 26;
}

int main() {
    fast_cin();
    
    ll t;
    cin >> t;

    int pivot = 0;
    ll last_n = 0;
    bool forward = true;
    vector<int> prev(26, 0);

    for (int i = 0; i < t; i++) {
        string command;
        cin >> command;
        if (command == "SMJER") {
            int n;
            cin >> n;

            if (n - last_n > 26) {
                int temp = (n - last_n) / 26;
                for (int j = 0; j < 26; j++) {
                    prev[j] += temp;
                }
            }

            for (int j = 0; j < (n - last_n) % 26; j++) {
                prev[pivot]++;
                pivot = increment_pivot(pivot, forward);
            }

            forward = !forward;
            pivot = increment_pivot(increment_pivot(pivot, forward), forward);
            last_n = n;

            // for (int j = 0; j < 26; j++) {
            //     cout << char(j + 'a') << ": " << prev[j] << ' ';
            // }
            // cout << "\n\n";
        } else if (command == "UPIT") {
            int n;
            char x;
            cin >> n >> x;

            int ans = ((n - last_n) / 26);
            if (forward) {
                int end = (pivot + n - last_n) % 26;
                if ((end >= pivot && (int(x - 'a') >= pivot && int(x - 'a') < end)) ||
                    (end < pivot && (int(x - 'a') >= pivot || int(x - 'a') < end))) {
                    ans++;
                }
            } else {
                int end = pivot - ((n - last_n) % 26);
                if (end < 0) {
                    end += 26;
                }
                if ((pivot >= end && (int(x - 'a') > end && int(x - 'a') <= pivot)) ||
                    (pivot < end && (int(x - 'a') > end || int(x - 'a') <= pivot))) {
                    ans++;
                }
            }
            cout << prev[int(x - 'a')] + ans << '\n';
        }
    }
}