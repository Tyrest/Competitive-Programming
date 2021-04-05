#include <bits/stdc++.h>
using namespace std;

int N;
bool cows[1000][1000];

void print_cows() {
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << cows[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	freopen("11.in", "r", stdin);
	freopen("main.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	string s;
	int rights = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		for (int j = 0; j < N; ++j)
		{
			cows[i][j] = s[j]=='R';
			if (s[j]=='R')
				rights++;
		}
	}

	bool majr = true;

	if (rights*2 < N*N)
		majr = false;

	bool solved = false;
	int count_col;
	int count_row;
	while (!solved) {
		solved = true;
		for (int i = 0; i < N; ++i)
		{
			count_row = 0;
			for (int j = 0; j < N; ++j)
			{
				if (cows[i][j]!=majr)
					count_row++;
			}
			if (count_row*2 > N || (count_row*2 == N && cows[i][0] == majr)) {
				solved = false;
				for (int j = 0; j < N; ++j)
					cows[i][j] = !cows[i][j];
			}
		}
		for (int i = 0; i < N; ++i)
		{
			count_col = 0;
			for (int j = 0; j < N; ++j)
			{
				if (cows[j][i]!=majr)
					count_col++;
			}
			if (count_col*2 > N || (count_col*2 == N && cows[0][i] == majr)) {
				solved = false;
				for (int j = 0; j < N; ++j)
					cows[j][i] = !cows[j][i];
			}
		}
	}

	print_cows();

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (cows[i][j]!=majr)
			{
				cout << i+1 << ' ' << j+1;
				return 0;
			}
		}
	}
	cout << -1;
}