#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define all(x) begin(x), end(x)
#define f first
#define s second

int N, M;

int main() {
	// freopen("21Open.in", "r", stdin);
	// freopen("21Open.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	char past[N][M];
	for (int i = 0; i < N; ++i)
		cin >> past[i];
	int ans = 0;
	for (int i = 1; i < N-1; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (past[i-1][j] == 'C' && past[i][j] == 'G' && past[i+1][j] == 'C')
			{
				past[i][j] = '.';
				ans++;
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j < M-1; ++j)
		{
			if (past[i][j-1] == 'C' && past[i][j] == 'G' && past[i][j+1] == 'C')
			{
				past[i][j] = '.';
				ans++;
			}
		}
	}
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			if ((past[i-1][j-1] == 'C' && past[i][j] == 'C' &&
				 (past[i][j-1] == 'G' || past[i-1][j] == 'G')) ||
				(past[i-1][j] == 'C' && past[i][j-1] == 'C' &&
				 (past[i][j] == 'G' || past[i-1][j-1] == 'G')))
				ans++;
		}
	}
	cout << ans;
}