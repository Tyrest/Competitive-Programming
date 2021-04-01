#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define f first
#define s second

int N;
vector<ll> cows;

int main() {
	ifstream fin("div7.in");
	ofstream fout("div7.out");

	fin >> N;
	cows.resize(N+1);

	int x;
	cows[0] = 0;
	for (int i = 1; i <= N; ++i)
	{
		fin >> x;
		cows[i] = cows[i-1] + x;
	}
	for (int i = N; i > 0; --i)
	{
		for (int j = 0; j <= N-i; ++j)
		{
			if (!((cows[j+i]-cows[j])%7))
			{
				fout << i;
				return 0;
			}
		}
	}
	fout << 0;
}