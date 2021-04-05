// Fails test 8 on time

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define f first
#define s second

int N, Q;
vector<vpi> edges;

int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> Q;
	edges.resize(N);
	int p1, q1, r1;
	for (int i = 0; i < N-1; ++i)
	{
		cin >> p1 >> q1 >> r1;
		edges[p1-1].push_back(make_pair(q1-1, r1));
		edges[q1-1].push_back(make_pair(p1-1, r1));
	}

	int k, v, count;
	queue<int> q;
	unordered_set<int> discovered;
	for (int i = 0; i < Q; ++i)
	{
		cin >> k >> v;
		count = 0;
		q.push(v-1);
		discovered.clear();
		discovered.insert(v-1);
		while (!q.empty()) {
			int v1 = q.front();
			// cout << v1 << '\n';
			vpi adj = edges[v1];
			q.pop();
			for (auto& a: adj)
			{
				if (!discovered.count(a.f) && a.s >= k) {
					// cout << a.f << '\n';
					discovered.insert(a.f);
					q.push(a.f);
					count++;
				}
			}
		}
		cout << count << '\n';
	}
}