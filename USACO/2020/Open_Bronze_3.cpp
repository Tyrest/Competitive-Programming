#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

int N, T;
vector<int> t, x, y;
bool infected_true[101];

void init() {
	string s;
	cin >> N >> T >> s;
	N++;

	for (int i = 1; i < N; ++i)
	{
		infected_true[i] = s[i-1]=='1';
	}
	t.resize(T); x.resize(T); y.resize(T);

	for (int i = 0; i < T; ++i) {
		cin >> t[i] >> x[i] >> y[i];
	}

	vector<int> inds(T);
	iota(all(inds), 0);
	sort(all(inds), [](int a, int b) {return t[a] < t[b];});

	vector<int> T, X, Y;

	for (auto &a : inds) {
		T.push_back(t[a]);
		X.push_back(x[a]);
		Y.push_back(y[a]);
	}

	swap(t, T); swap(x, X); swap(y, Y);
}

bool simulate(int p0, int K) {
	// cout << p0 << ' ' << K << '\n';
	bool cows[N] = {};
	int cowsK[N] = {};
	cows[p0] = true;
	for (int i = 0; i < T; ++i)
	{
		int cowx = x[i], cowy = y[i];
		if (cows[cowx]) cowsK[cowx]++;
		if (cows[cowy]) cowsK[cowy]++;
		if (cows[cowx] && cowsK[cowx] <= K)
			cows[cowy] = true;
		if (cows[cowy] && cowsK[cowy] <= K)
			cows[cowx] = true;
	}

	// for (int i = 1; i < N; ++i)
	// {
	// 	cout << cows[i];
	// }
	// cout << '\n';

	for (int i = 1; i < N; ++i)
	{
		if (cows[i] != infected_true[i])
			return false;
	}
	// cout << "WORKS" << '\n';
	return true;
}

int main() {
	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	init();
	int minK=251, maxK=0;
	unordered_set<int> p0s;
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j <= T; ++j)
		{
			if (simulate(i, j))
			{
				p0s.insert(i);
				if (j < minK) minK = j;
				if (j > maxK) maxK = j;
			}
		}
	}

	cout << p0s.size() << ' ' << minK << ' ';
	if (maxK == T) cout << "Infinity";
	else cout << maxK;
}