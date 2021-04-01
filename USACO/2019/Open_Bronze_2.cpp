#include <bits/stdc++.h>
using namespace std;

int N;
// unordered_set<int> paths[101];

int main() {
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	unordered_set<int> starts, ends;

	int a, b;

	for (int i = 0; i < N-1; ++i)
	{
		cin >> a >> b;
		if (starts.count(a)) {cout << -1; return 0;}
		starts.insert(a);
		ends.insert(b);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!starts.count(i)) {cout << i; break;}
	}

	// for (int i = 1; i <= N; ++i)
	// 	paths[i].insert(i);

	// int a, b;
	// for (int i = 0; i < N-1; ++i)
	// {
	// 	cin >> a >> b;
	// 	paths[b].insert(a);
	// 	for (auto& x : paths[a])
	// 		paths[b].insert(x);
	// 	for (int j = 1; j <= N; ++j)
	// 	{
	// 		if (paths[j].count(b))
	// 			paths[j].insert(a);
	// 	}
	// }

	// bool end_station;
	// for (int i = 1; i <= N; ++i)
	// {
	// 	end_station = true;
	// 	for (int j = 1; j <= N; ++j)
	// 	{
	// 		// cout << i << "," << j << ": " << paths[i].count(j) << '\n';
	// 		if (!paths[i].count(j)) {end_station = false; break;}
	// 	}
	// 	if (end_station) {cout << i; return 0;}
	// }
	// cout << -1;
}