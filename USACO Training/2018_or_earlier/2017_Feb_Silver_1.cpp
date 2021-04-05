#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define f first
#define s second

int C, N;
vi chickt;
vpi cowt;

int main() {
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> C >> N;
	chickt.resize(C);
	cowt.resize(N);
	for (int i = 0; i < C; ++i)
		cin >> chickt[i];
	for (int i = 0; i < N; ++i)
		cin >> cowt[i].s >> cowt[i].f; // cow[i] = (end_time, start_time)

	sort(all(chickt));
	sort(all(cowt));
	int i, count = 0;

	for (auto& a : chickt) {
		// cout << a << '\n';
		i = 0;
		while (i < cowt.size()) {
			// cout << "cow: " << cowt[i].f << " " << i << '\n';
			if (a > cowt[i].f) {
				cowt.erase(cowt.begin()+i);
			}
			else if (a >= cowt[i].s) {
				// cout << "cowtime: " << cowt[i].f << " " << i << '\n';
				cowt.erase(cowt.begin()+i);
				count++;
				break;
			}
			else i++;
		}
	}

	cout << count;
}