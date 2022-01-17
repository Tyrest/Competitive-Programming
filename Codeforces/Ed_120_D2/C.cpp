#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define deb(x) cout << #x << ": " << x << '\n'
#define deb2(x, y) cout << #x << ": " << x << "," << #y << ": " << y << '\n'

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second

const ll INF = 1e18;
const ld PI = 4*atan((ld)1);

void setIO(string s) {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void solve()
{
    int n, k, t=0;
    cin >> n >> k;
    vi a;
    a.rsz(n);
    F0R(i, n)
    {
        cin >> a[i];
        t += a[i];
    }
    if (t <= k)
    {
        cout << 0 << '\n';
        return;
    }
    sort(all(a));
    int i = n - 1;
    int c = 1;
    int e = 0;
    int x = 0;
    int ans = 0;
    while (t - e + a[0] * (c - 1) - x > k)
    {
        if (i > 0 && a[i] - a[0] >= c)
        {
            e += a[i];
            ++c;
            --i;
        }
        else
        {
            --a[0];
            ++x;
        }
        ++ans;
    }
    cout << ans << '\n';
}

int main() {
	#ifndef ONLINE_JUDGE
	setIO("main");
	#endif
	// setIO("problem_name"); // Set this to the problem name
    
    int t;
    cin >> t;
    while(t--)
        solve();
}