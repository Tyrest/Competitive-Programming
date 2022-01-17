#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define deb(x) cout << #x << ": " << x << '\n'
#define deb2(x, y) cout << #x << ": " << x << "," << #y << ": " << y << '\n'

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second

const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);

void setIO(string s)
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p;
    p.rsz(n);
    F0R(i, n)
        cin >> p[i];
    string likes;
    cin >> likes;
    vi l_inds, d_inds;
    int num_d = 0;
    F0R(i, n)
        if (likes[i] == '0')
            ++num_d;
    F0R(i, n)
    {
        if (likes[i] == '0' && p[i] > num_d)
            d_inds.pb(i);
        else if (likes[i] == '1' && p[i] <= num_d)
            l_inds.pb(i);
    }
    F0R(i, (sz(d_inds) + sz(l_inds)) / 2)
    {
        int tmp = p[d_inds[i]];
        p[d_inds[i]] = p[l_inds[i]];
        p[l_inds[i]] = tmp;
    }
    trav(a, p)
        cout << a << ' ';
    cout << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    setIO("main");
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);
    // setIO("problem_name"); // Set this to the problem name
    int t;

    cin >> t;
    while (t--)
        solve();
}