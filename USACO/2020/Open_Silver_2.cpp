#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<pair<int, int>> vpi;

#define f first
#define s second

#define MAX 100001
int N, M;
int fc[MAX];
int sc[MAX];
int taken[MAX];
int ans[MAX];

int main() {
	freopen("cereal.in", "r", stdin);
	freopen("cereal.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> fc[i] >> sc[i];
	int count = 0;
	for (int i = N-1; i >= 0; --i)
	{
		int j = i;
		int cer = fc[i];
		while (1) {
			if (!taken[cer]) {
				taken[cer] = j;
				count++;
				break;
			}
			else if (taken[cer] < j)
				break;
			else {
				int k = taken[cer];
				taken[cer] = j;
				if (cer == sc[k])
					break;
				j = k;
				cer = sc[k];
			}
		}
		ans[i] = count;
	}
	for (int i = 0; i < N; ++i)
		cout << ans[i] << '\n';
}
// 	unordered_set<int> taken;
// 	for (int i = 0; i < N; ++i) {
// 		if (!taken.count(cows[i].f)) taken.insert(cows[i].f);
// 		else if (!taken.count(cows[i].s)) taken.insert(cows[i].s);
// 	}
// 	int count = taken.size();
// 	cout << count;
// 	// Two cases for removing the first cow:
// 	// Count decreases because no one wants the extra cereal
// 	// Count stays the same because someone sweeps the extra cereal

// }

// 	unordered_set<int> taken;
// 	unordered_set<int> not_counted;
// 	for (int i = 0; i < N; ++i) {
// 		if (!taken.count(cows[i].f)) taken.insert(cows[i].f);
// 		else if (!taken.count(cows[i].s)) taken.insert(cows[i].s);
// 		else not_counted.insert(i);
// 	}
// 	int count = taken.size();
// 	cout << count << '\n';
// 	for (int i = 1; i < N; ++i)
// 	{
// 		count--;
// 		int prev = cows[i-1].f;
// 		for (int j = i; j < N; ++j)
// 		{
// 			if (cows[j].f == prev)
// 			{
// 				prev = cows[j].s;
// 				if (not_counted.count(j)) {count++; not_counted.erase(j);}
// 			}
// 			else if (cows[j].s == prev)
// 			{
// 				if (not_counted.count(j)) {count++; not_counted.erase(j);}
// 				break;
// 			}
// 		}
// 		cout << count << '\n';
// 	}
// }