// Solves first 5 and fails on time for the last 5
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define all(x) begin(x), end(x)
#define f first
#define s second

int N, M;
vi cows, wids;
vpi worms;
unordered_set<int> unsorted;
vector<unordered_set<int>> groups;

bool itergroups() {
	for (auto& group : groups)
		for (auto& a : group)
			if (!group.count(cows[a]))
				return false;
	return true;
}

int main() {
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	cows.resize(N+1);
	wids.resize(M); worms.resize(M);
	for (int i = 1; i <= N; ++i) {
		cin >> cows[i];
		if (i != cows[i])
			unsorted.insert(i);
	}
	for (int i = 0; i < M; ++i)
		cin >> worms[i].f >> worms[i].s >> wids[i];
	vi inds(M);
	iota(all(inds), 0);
	sort(all(inds), [](int a, int b) {return wids[a] > wids[b];});
	vpi Worms;
	vi Wids;
	for (auto& a : inds) {
		Worms.push_back(worms[a]);
		Wids.push_back(wids[a]);
	}
	swap(worms, Worms);
	swap(wids, Wids);

	int last_wid = -1;
	for (int i = 0; i < M; ++i)
	{
		if (itergroups() && unsorted.empty()) {cout << last_wid; return 0;}
		int s1, s2, j=0;
		int cases = 0, a = worms[i].f, b = worms[i].s;
		unsorted.erase(a);
		unsorted.erase(b);
		for (auto& group : groups) {
			if (group.count(a)||group.count(b)) {
				if (!cases) s1 = j;
				else s2 = j;
				cases++;
			}
			j++;
		}
		// Should create a new group
		if (!cases) {
			unordered_set<int> temp;
			temp.insert({a, b});
			groups.push_back(temp);
		}
		// Should add a and b to group
		else if (cases == 1) {
			groups[s1].insert(a);
			groups[s1].insert(b);
		}
		// Should combine the two sets and remove one from the group
		else {
			groups[s1].insert(all(groups[s2]));
			groups.erase(groups.begin()+s2);
		}

		last_wid = wids[i];
	}
	cout << last_wid;
}