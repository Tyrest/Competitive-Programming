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

    vector<string> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];
    
    for (int i = 0; i < 8; i++) {
        bool r = false, c = false;
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == '*') {
                if (r) {
                    cout << "invalid";
                    return 0;
                }
                r = true;
            }
            if (board[j][i] == '*') {
                if (c) {
                    cout << "invalid";
                    return 0;
                }
                c = true;
            }
        }
    } 

    for (int i = 0; i < 13; i++) {
        bool f = false, b = false;
        for (int j = 0; j < 8 - abs(6 - i); j++) {
            // cout << max(i - 6, 0) + j << ' ' << min(1 + i, 7) - j << '\n';
            if (board[max(i - 6, 0) + j][min(1 + i, 7) - j] == '*') {
                if (f) {
                    cout << "invalid";
                    return 0;
                }
                f = true;
            }
            // cout << max(6 - i, 0) + j << ' ' << max(0, i - 6) + j << '\n';
            if (board[max(6 - i, 0) + j][max(0, i - 6) + j] == '*') {
                if (b) {
                    cout << "invalid";
                    return 0;
                }
                b = true;
            }
        }
        // cout << '\n';
    }

    cout << "valid";
}