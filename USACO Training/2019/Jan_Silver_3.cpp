#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define f first
#define s second

int N;
vpi peaks;
vpi peaks_seen;

bool viewable(pair<int, int> peak) {
	for (auto& a : peaks_seen) {
		if (a.f-peak.f>=abs(a.s-peak.s))
			return false;
	}
	peaks_seen.push_back(peak);
	return true;
}

int main() {
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N;
	peaks.resize(N);
	// peaks = (y, x)
	for (int i = 0; i < N; ++i)
		cin >> peaks[i].s >> peaks[i].f;
	// sort(all(peaks));
	sort(all(peaks), [](pair<int, int> a, pair<int, int> b) {return a.f > b.f;});
	int count = 0;
	for (auto& a : peaks) {
		// cout << a.s << a.f << '\n';
		if (viewable(a)) count++;
	}
	cout << count;
}