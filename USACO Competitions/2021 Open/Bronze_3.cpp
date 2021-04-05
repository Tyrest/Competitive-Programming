#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define all(x) begin(x), end(x)
#define f first
#define s second

int N, M;
char past[1000][1000];
map<int, unordered_set<int>> friends;

// Returns false if already friends
bool friend_check(int orow, int ocol, int crow, int ccol) {
	int opos = orow*N+ocol;
	int cpos = crow*N+ccol;
	if (!friends[opos].count(cpos)) {
		friends[opos].insert(cpos);
		friends[cpos].insert(opos);
		// cout << "NEW " << orow << " " << ocol << " " << crow << " " << ccol << '\n';
		return true;
	}
	return false;
}

void grass_check(int row, int col, int orow, int ocol) {
	// cout << "GROW: " << row << " GCOL: " << col << '\n';
	if (row-1 != orow && row > 0 && past[row-1][col] == 'C') {
		if (friend_check(orow, ocol, row-1, col)) {past[row][col] = '.'; return;}
	}
	if (row+1 != orow && row < N-1 && past[row+1][col] == 'C') {
		if (friend_check(orow, ocol, row+1, col)) {past[row][col] = '.'; return;}
	}
	if (col-1 != ocol && col > 0 && past[row][col-1] == 'C') {
		if (friend_check(orow, ocol, row, col-1)) {past[row][col] = '.'; return;}
	}
	if (col+1 != ocol && col < N-1 && past[row][col+1] == 'C') {
		if (friend_check(orow, ocol, row, col+1)) {past[row][col] = '.'; return;}
	}
	// cout << "GRASS FAIL" << '\n';
}

void cow_check(int row, int col) {
	if (row > 0 && past[row-1][col] == 'G') {
		grass_check(row-1, col, row, col);
	}
	if (row < N-1 && past[row+1][col] == 'G') {
		grass_check(row+1, col, row, col);
	}
	if (col > 0 && past[row][col-1] == 'G') {
		grass_check(row, col-1, row, col);
	}
	if (col < N-1 && past[row][col+1] == 'G') {
		grass_check(row, col+1, row, col);
	}
}

int main() {
	freopen("21Open.in", "r", stdin);
	freopen("21Open.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> past[i];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (past[i][j] == 'C')
			{
				// cout << "ROW: " << i << " COL: " << j << '\n';
				cow_check(i, j);
			}
		}
	}

	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < M; ++j)
	// 	{
	// 		cout << past[i][j];
	// 	}
	// 	cout << '\n';
	// }
	int ans = 0;
	for (auto& a : friends) {
		ans += int(a.s.size());
	}
	cout << ans/2;
}