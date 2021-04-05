#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define f first
#define s second

long long L, N, rF, rB, S; // S = speed diff
vi pos, taste;

int greatest_tastiness(int cur_i) {
	int max_i=-1, max_t = 0;
	for (int i = cur_i+1; i < N; ++i)
	{
		if (taste[i]>=max_t)
		{
			max_i = i;
			max_t = taste[i];
		}
	}
	return max_i;
}

int main() {
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> L >> N >> rF >> rB;
	S = rF - rB;
	pos.resize(N); taste.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> pos[i] >> taste[i];

	int last_pos = 0;
	long long points = 0;
	int max_i = greatest_tastiness(-1);
	while (max_i != -1) {
		points += S * (pos[max_i]-last_pos) * taste[max_i];
		// cout << points << '\n';
		last_pos = pos[max_i];
		max_i = greatest_tastiness(max_i);
	}
	cout << points;
}