#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

int N, M;
char milk[100001];
int groups[100001];
vector<unordered_set<int>> edges;

int main() {
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	edges.resize(N);
	cin >> milk;
	for (int i = 0; i < N-1; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a-1].insert(b-1);
		edges[b-1].insert(a-1);
	}
	unordered_set<int> discovered;
	int group = 1;
	for (int i = 0; i < N; ++i)
	{
		char color = milk[i];
		if (!discovered.count(i)) {
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int x = q.front();
				q.pop();
				if (!discovered.count(x) && milk[x]==color) {
					discovered.insert(x);
					groups[x] = group;
					for (auto& a : edges[x])
						q.push(a);
				}
			}
			group++;
		}
	}
	while (M--) {
		char m;
		int a, b;
		cin >> a >> b >> m;
		if (groups[a-1]==groups[b-1]) {
			if (milk[a-1]==m) cout << 1;
			else cout << 0;
		}
		else cout << 1;
	}
}