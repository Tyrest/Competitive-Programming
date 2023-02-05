#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	vector<int> f;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;
		f.push_back(t - 1);
	}

	vector<set<int>> cnt;
	for (int i = 0; i < n; i++)
	{
		cnt.push_back({ i });
	}

	for (int i = 0; i < n; i++)
	{
		int spot = i;
		for (int j = 0; j < n; j++)
		{
			cnt[i].insert(f[spot]);
			spot = f[spot];
		}
	}

	set<set<int>> finalSols;
	for (int i = 0; i < n; i++)
	{
		finalSols.insert(cnt[i]);
	}

	for (auto i = finalSols.begin(); i != finalSols.end(); i++)
	{
		for (auto j = finalSols.begin(); j != finalSols.end(); j++)
		{
			if (*(i->begin()) == *(j->begin())) continue;
			std::set<int> m;
			merge(i->begin(), i->end(), j->begin(), j->end(), inserter(m, m.begin()));
			finalSols.insert(m);
		}
	}

	std::cout << finalSols.size() % (int(pow(10, 9)) + 7);

	return 0;
}