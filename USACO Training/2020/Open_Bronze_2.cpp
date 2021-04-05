#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("socdist2.in", "r", stdin);
	freopen("socdist2.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	// Find maximum R
	int N;
	cin >> N;

	set<int> sick;
	unordered_set<int> healthy;
	int x, stat;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> stat;
		if (stat==1) sick.insert(x);
		else healthy.insert(x);
	}

	int R = 10e6;
	for (auto& a : healthy) {
		if (sick.upper_bound(a) != end(sick) && *sick.upper_bound(a)-a < R)
			R = *sick.upper_bound(a)-a;
		if (sick.upper_bound(a) != begin(sick) && a-*(--sick.upper_bound(a)) < R)
			R = a-*(--sick.upper_bound(a));
	}

	// Count groups
	int count = 1;
	int last = *begin(sick);
	for (auto&a : sick) {
		if (a - last >= R) count++;
		last = a;
	}

	cout << count;
}