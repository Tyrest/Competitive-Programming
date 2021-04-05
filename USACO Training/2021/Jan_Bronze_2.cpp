#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

int main() {
	// freopen("main.in", "r", stdin);
	// freopen("main.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	int x, evens = 0, odds = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		if (x%2 == 0) evens++;
		else odds++;
	}
	while (evens<odds)
	{
		evens++;
		odds-=2;
	}
	if (odds == evens) cout << 2*odds;
	else cout << 2*odds+1;
}