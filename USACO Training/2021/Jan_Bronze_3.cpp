#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

int N;
vector<int> cows;
multiset<int> stalls;

int main() {
	// freopen("main.in", "r", stdin);
	// freopen("main.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	cows.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> cows[i];
	int height;
	for (int i = 0; i < N; ++i)
	{
		cin >> height;
		stalls.insert(height);
	}

	sort(all(cows),[](int a, int b) {return b < a;});
	long long perms = 1;
	auto end = stalls.end();
	for (auto& a : cows)
	{
		auto lowest = stalls.lower_bound(a);
		perms *= distance(lowest, stalls.end());
		stalls.erase(lowest);
	}
	cout << perms;
}