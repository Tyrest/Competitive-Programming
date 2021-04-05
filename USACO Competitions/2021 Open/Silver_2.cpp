#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define all(x) begin(x), end(x)
#define f first
#define s second

int T, N;
vi nums;

bool test(int a, int b, int c) {
	unordered_set<ll> test;
	test.insert({a, b, c, a+b, a+c, b+c, a+b+c});
	for (int i = 0; i < N; ++i)
	{
		if (!test.count(nums[i]))
			return false;
	}
	return true;
}

void solve() {
	cin >> N;
	vi pabc;
	pabc.resize(10);
	nums.clear();
	nums.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> nums[i];
	sort(all(nums));
	pabc[0] = nums[0];
	pabc[1] = nums[1];
	pabc[2] = nums[2];
	pabc[3] = nums[3];
	pabc[4] = nums[3]-nums[0];
	pabc[5] = nums[3]-nums[1];
	pabc[6] = nums[3]-nums[2];
	pabc[7] = nums[2]-nums[0];
	pabc[8] = nums[2]-nums[1];
	pabc[9] = nums[1]-nums[0];
	sort(all(pabc));
	int a = -1, b = -1, c = -1, ans = 0;
	for (int i = 0; i < 8; ++i)
	{
		while (a == pabc[i])
			i++;
		a = pabc[i];
		for (int j = i+1; j < 9; ++j)
		{
			while (b == pabc[j])
				j++;
			b = pabc[j];
			for (int k = j+1; k < 10; ++k)
			{
				while (c == pabc[k])
					k++;
				c = pabc[k];
				if (test(a, b, c))
					ans++;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> T;
	while (T--)
		solve();
}