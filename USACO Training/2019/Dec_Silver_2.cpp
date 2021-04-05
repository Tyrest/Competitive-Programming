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

int N, L;
vi w, x, d;

// Read input and sort all lists in order of x
void init() {
	// Read input
	cin >> N >> L;
	w.rsz(N); x.rsz(N); d.rsz(N);
	F0R(i,N)
		cin >> w[i] >> x[i] >> d[i];

	// Create list of indices ordered as they would be on the number line
	vi inds(N);
	iota(all(inds), 0);
	sort(all(inds), [](int a, int b) {return x[a] < x[b];});

	// Re-sort the vectors to be in the indices order
	vi W, X, D;
	trav(a,inds) {
		W.pb(w[a]);
		X.pb(x[a]);
		D.pb(d[a]);
	}
	swap(w, W); swap(x, X); swap(d, D);
}

int get_time() {
	vi left, right;
	F0R(i,N) {
		if(d[i]==-1) {
			left.pb(x[i]);
		}
		else {
			right.pb(x[i]);
		}
	}
	vpi tandw;
	F0R(i,sz(left)) {
		tandw.pb({left[i], w[i]});
	}
	F0R(i,sz(right)) {
		tandw.pb({L-right[i], w[sz(left)+i]});
	}
	sort(all(tandw));
	int total = 0;
	trav(x,tandw) total+=x.s;
	trav(x,tandw) {
		total-=2*x.s;
		if(total <= 0) {
			return x.f;
		}
	}
}

int find_collisions(int t) {
	queue<int> right;
	int collisions = 0;
	F0R(i, sz(x)) {
		if(d[i]==-1) {
			while(sz(right) && x[i]-right.front() > t*2)
				right.pop();
			collisions += sz(right);
		}
		else {
			right.push(x[i]);
		}
	}
	return collisions;
}

int main() {
	// #ifndef ONLINE_JUDGE
	// setIO("main");
	// #endif
	setIO("meetings"); // Set this to the problem name
    
    int i, j, n, m, x, y;

    init();
    int t = get_time();
    cout << find_collisions(t);
}