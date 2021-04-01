#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;

#define f first
#define s second

int N;
vpi cows;
int psum[2501][2501];

int rsum(int x1, int y1, int x2, int y2) {
	return psum[x2+1][y2+1] - psum[x1][y2+1] - psum[x2+1][y1] + psum[x1][y1];
}

int main() {
	freopen("main.in", "r", stdin);
	freopen("main.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N;
	cows.resize(N);
	int x, y;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		cows[i] = make_pair(x, y);
	}
	sort(all(cows));
	for (int i = 0; i < N; ++i) cows[i].f = i;
	sort(all(cows), [](pi a, pi b) {return a.s < b.s;});
	for (int i = 0; i < N; ++i) cows[i].s = i;
	for (auto& a : cows) psum[a.f+1][a.s+1]++;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
		}
	}

	ll count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			int x1 = cows[i].f, x2 = cows[j].f;
			// cout << i << " " << j << ": " << rsum(0, i, min(x1, x2), j) * rsum(max(x1, x2), i, N-1, j) << '\n';
			count += rsum(0, i, min(x1, x2), j) * rsum(max(x1, x2), i, N-1, j);
		}
	}
	cout << count + 1;
}