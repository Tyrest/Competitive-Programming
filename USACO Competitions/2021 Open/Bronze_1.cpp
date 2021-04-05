#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define all(x) begin(x), end(x)
#define f first
#define s second

int N, L;
vi cits;

int main() {
	// freopen("21Open.in", "r", stdin);
	// freopen("21Open.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> L;
	cits.resize(N+1);
	for (int i = 0; i < N; ++i)
		cin >> cits[i];
	sort(all(cits), [](int a, int b) {return a > b;});
	int prev = 100001;
	int count_same = 1;
	for (int i = 0; i < N; ++i)
	{
		if (prev == cits[i])
			count_same++;
		else
			count_same = 1;
		if (cits[i] == i)
		{
			// cout << count_same << '\n';
			if (count_same <= L) {cout << i+1; return 0;}
			cout << i;
			return 0;
		}
		else if (cits[i] < i)
		{
			cout << i;
			return 0;
		}
		prev = cits[i];
	}
	cout << N;
}