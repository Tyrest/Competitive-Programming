#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<pair<int, int>> vpi;

#define f first
#define s second

int N, M;
vpi parts;
vpi mnm;

int main() {
	freopen("moop.in", "r", stdin);
	freopen("moop.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N;
	parts.resize(N);
	mnm.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> parts[i].f >> parts[i].s;
	sort(all(parts));
	mnm[0].f = parts[0].s;
	mnm[N-1].s = parts[N-1].s;
	for (int i = 1; i < N; ++i)
	{
		mnm[N-1-i].s = max(mnm[N-i].s, parts[N-i].s);
		mnm[i].f = min(mnm[i-1].f, parts[i].s);
	}
	// for (int i = 0; i < N; ++i)
	// {
	// 	cout << mnm[i].f << " " << mnm[i].s << '\n';
	// }
	int ans = 1;
	for (int i = 0; i < N; ++i)
	{
		if (mnm[i].f > mnm[i].s) ans++;
	}
	cout << ans;
}