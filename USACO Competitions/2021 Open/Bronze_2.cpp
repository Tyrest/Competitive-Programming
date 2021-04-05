#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define all(x) begin(x), end(x)
#define f first
#define s second

int K, N;
int ans[100][100];
map<string, int> place;

int main() {
	// freopen("21Open.in", "r", stdin);
	// freopen("21Open.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> K >> N;
	for (int i = 0; i < N; ++i)
	{
		string name;
		cin >> name;
		place[name] = i;
	}
	for (int i = 0; i < K; ++i)
	{
		unordered_set<string> names_prev;
		unordered_set<string> juniors;
		string prev, curr;
		cin >> prev;
		names_prev.insert(prev);
		for (int j = 1; j < N; ++j)
		{
			cin >> curr;
			if (prev.compare(curr)>0) {
				juniors.insert(all(names_prev));
			}
			for (auto& name : juniors) {
				ans[place[curr]][place[name]]=1;
				ans[place[name]][place[curr]]=-1;
			}
			prev = curr;
			names_prev.insert(curr);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j) cout << "B";
			else if (ans[i][j] == -1) cout << 0;
			else if (ans[i][j] == 1) cout << 1;
			else cout << "?";
		}
		cout << '\n';
	}
}