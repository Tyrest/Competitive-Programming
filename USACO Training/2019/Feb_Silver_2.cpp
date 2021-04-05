#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define f first
#define s second

int N, K;
int arr[1001][1001];

int main() {
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> K;

	while (N--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		arr[x1][y1]++;
		arr[x1][y2]--;
		arr[x2][y1]--;
		arr[x2][y2]++;
	}
	int count = 0;
	for (int i = 0; i < 1001; ++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			if (i) arr[i][j] += arr[i-1][j];
			if (j) arr[i][j] += arr[i][j-1];
			if (i && j) arr[i][j] -= arr[i-1][j-1];
			if (arr[i][j]==K) count++;
		}
	}
	cout << count;
}