#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, l;
        cin >> n >> m >> l;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        for (int j = 0; j < l; j++) {
            int n_j = n;

            string input;
            cin >> input;
            string name = input.substr(0, input.find(':'));
            int A = atoi(input.substr(input.find(':') + 1, input.find(',')).c_str());
            int B = atoi(input.substr(input.find(',') + 1, input.size()).c_str());

            int halfs = 0, ones = 0;
            while (n_j > m) {
                if ((n_j - n_j / 2) * A > B && n_j / 2 >= m) {
                    halfs++;
                    n_j /= 2;
                } else {
                    ones++;
                    n_j--;
                }
            }

            pq.push(make_pair(A * ones + B * halfs, name));
        }

        cout << "Case " << i + 1 << '\n';

        while (!pq.empty()) {
            cout << pq.top().second << ' ' << pq.top().first << '\n';
            pq.pop();
        }
    }
}