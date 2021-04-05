#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define all(x) begin(x), end(x)
#define f first
#define s second

int N, K, L;
vi cits;

bool ok(int h) {
	int tcn = 0; // total citations needed;
	for (int i = 0; i < h; ++i)
	{
		if (cits[i] < h)
		{
			tcn += h - cits[i];
		}
	}
	if (tcn <= K * L && h - cits[h-1] <= K)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> K >> L;
	cits.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> cits[i];
	sort(all(cits), [](int a, int b) {return a > b;});
	int lo = 1;
	int hi = N;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (ok(mid))
		{
			ans = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	cout << ans;
}