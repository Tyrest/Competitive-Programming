#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

ll N;

int main() {
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int extra[8] = {14, 1, 2, 4, 7, 8, 11, 13};
	cin >> N;
	cout << (N-1)/8*15+extra[N%8];
}