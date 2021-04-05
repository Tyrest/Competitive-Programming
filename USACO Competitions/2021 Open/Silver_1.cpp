#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define all(x) begin(x), end(x)
#define f first
#define s second

class board {
	char b[3][3];
public:
	board() {
		for (int i = 0; i < 9; ++i)
		{
			b[i/3][i%3] = '.';
		}
	}
	bool finished() {
		for (int i = 0; i < 3; ++i)
		{
			if ((b[i][0] == 'M' && b[i][1] == 'O' && b[i][2] == 'O') ||
				(b[i][2] == 'M' && b[i][1] == 'O' && b[i][0] == 'O') ||
				(b[0][i] == 'M' && b[1][i] == 'O' && b[2][i] == 'O') ||
				(b[2][i] == 'M' && b[1][i] == 'O' && b[0][i] == 'O'))
				return true;
		}
		if (b[1][1] == 'O')
		{
			if ((b[0][0] == 'M' && b[2][2] == 'O') ||
				(b[2][2] == 'M' && b[0][0] == 'O') ||
				(b[0][2] == 'M' && b[2][0] == 'O') ||
				(b[2][0] == 'M' && b[0][2] == 'O'))
				return true;
		}
		return false;
	}
	void add_piece(int row, int col, char piece) {
		if (b[row-49][col-49] == '.')
		{
			b[row-49][col-49] = piece;
		}
	}
	void print() {
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << b[i][j];
			}
			cout << '\n';
		}
	}
};

int N;
char moves[530][3]; // Token, row, col
unordered_set<int> edges[530];
int field[25][25];

int dfs(int c, unordered_set<int>& dlast, board b) {
	if (c)
	{
		b.add_piece(moves[c][1], moves[c][2], moves[c][0]);
		b.print();
		cout << '\n';
	}
	if (b.finished()) {return 1;}

	unordered_set<int> discovered;
	discovered.insert(all(dlast));
	discovered.insert(c);
	int sum = 0;
	for (auto& a : edges[c])
	{
		if (!discovered.count(a))
		{
			discovered.insert(a);
			sum += dfs(a, discovered, b);
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N;
	int count = 1;
	char input[N*3];
	int startr = 0, startc = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		for (int j = 0; j < N*3; j+=3)
		{
			if (input[j] == '#') {field[i][j/3] = -2;}
			else if (input[j] == '.') {field[i][j/3] = -1;}
			else if (input[j] == 'B')
			{
				field[i][j/3] = 0;
				startr = i;
				startc = j;
			}
			else
			{
				field[i][j/3] = count;
				moves[count][0] = input[j];
				moves[count][1] = input[j+1];
				moves[count][2] = input[j+2];
				count++;
			}
		}
	}
	queue<pair<int, int>> Q;
	unordered_set<int> discovered;
	Q.push(make_pair(startr, startc));
	while (!Q.empty())
	{
		queue<pair<int, int>> q;
		pair<int, int> POS = Q.front();
		unordered_set<int> adj;
		adj.insert(field[POS.f][POS.s]);
		field[POS.f][POS.s] = -1;
		q.push(POS);
		Q.pop();
		
		while (!q.empty())
		{
			pair<int, int> pos = q.front();
			q.pop();
			if (field[pos.f][pos.s] != -2 &&
				!discovered.count(pos.f*N+pos.s))
			{
				if (field[pos.f][pos.s] == -1)
				{
					q.push(make_pair(pos.f+1, pos.s));
					q.push(make_pair(pos.f-1, pos.s));
					q.push(make_pair(pos.f, pos.s+1));
					q.push(make_pair(pos.f, pos.s-1));
					discovered.insert(pos.f*N+pos.s);
				}
				else
				{
					adj.insert(field[pos.f][pos.s]);
					Q.push(make_pair(pos.f, pos.s));
				}
			}
		}

		for (auto& a : adj)
			for (auto& b : adj)
				if (a != b)
					edges[a].insert(b);
	}
	for (auto& a : edges[0])
		for (auto& b : edges[0])
			if (a != b)
				edges[a].insert(b);
	for (int i = 0; i < count; ++i)
	{
		for (auto& a : edges[i])
		{
			cout << a << ' ';
		}
		cout << '\n';
	}
	unordered_set<int> d;
	d.insert(0);
	board b;
	int ans = 0;
	for (auto& a : edges[0])
		ans += dfs(a, d, b);
	cout << ans;
}