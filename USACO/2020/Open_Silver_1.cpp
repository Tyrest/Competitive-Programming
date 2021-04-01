#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<pair<int, int>> vpi;

#define f first
#define s second

int N, M;
vpi grass;

bool ok(ll D) {
	int count = 0;
	ll left = 0;
	for (auto& a : grass) {
		left = max(left, (ll) a.f);
		while (left <= a.s) {
			count++;
			left += D;
		}
		if (count >= N) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	grass.resize(M);
	for (int i = 0; i < M; ++i)
		cin >> grass[i].f >> grass[i].s;
	sort(all(grass));
	ll lo = 1, hi = 10e17, ans = -1;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		// cout << mid << '\n';
		if (ok(mid)) {
			ans = mid;
			lo = mid + 1;
		}
		else {
			hi = mid-1;
		}
	}
	cout << ans;
}