#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef vector<int> vi;

int N;
vi cows;

int main() {
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N;
	cows.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> cows[i];
	sort(all(cows), [](int a, int b) {return a > b;});
	for (int i = 0; i < N; ++i)
		if (cows[i] < i) {cout << i; return 0;}
	cout << N;
}