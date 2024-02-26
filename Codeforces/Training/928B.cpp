#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string l1, l2, l3;
        if (n == 2) {
            cin >> l1 >> l2;
            cout << "SQUARE\n";
            continue;
        }

        bool done = false;
        cin >> l2 >> l3;
        for (int i = 0; i < n && !done; i++) {
            if (l2[i] == '1' && l3[i] == '0') {
                cout << "TRIANGLE\n";
                done = true;
            }
        }
        for (int i = 2; i < n; i++) {
            l1 = l2; l2 = l3;
            cin >> l3;
            for (int j = 0; j < n && !done; j++) {
                if (l1[j] == l3[j] && l1[j] != l2[j]) {
                    cout << "TRIANGLE\n";
                    done = true;
                }
            }
        }
        for (int i = 0; i < n && !done; i++) {
            if (l2[i] == '0' && l3[i] == '1') {
                cout << "TRIANGLE\n";
                done = true;
            }
        }
        if (!done) {
            cout << "SQUARE\n";
        }
    }
    
}
