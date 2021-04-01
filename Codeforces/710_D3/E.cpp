#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FO(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define RO(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(x)	scanf("%s",&x)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(x)	printf("%s\n",x)
#define deb(x) cout << #x << ": " << x << '\n'
#define deb2(x, y) cout << #x << ": " << x << "," << #y << ": " << y << '\n'

const ll INF = 1e18;
const ld PI = 4*atan((ld)1);

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void solve() {
	int i, j, n, m, k, x, y, z;

	cin >> n;

	int a[n];
	set<int> nums;
	cin >> a[0];
	cout << a[0];
	int cmax=a[0];
	FOR(j,1,a[0]){
		nums.insert(j);
	}
	FOR(i,1,n){
		cin>>a[i];
		if (cmax!=a[i]){
			FOR(j,cmax+1,a[i]){
				nums.insert(j);
			}
			cmax=a[i];
			cout << ' ' << a[i];
		}
		else{
			cout << ' ' << *nums.begin();
			nums.erase(*nums.begin());
		}
	}
	cout << '\n';

	nums.clear();
	cout << a[0];
	cmax=a[0];
	FOR(j,1,a[0]){
		nums.insert(j);
	}
	FOR(i,1,n){
		if (cmax!=a[i]){
			FOR(j,cmax+1,a[i]){
				nums.insert(j);
			}
			cmax=a[i];
			cout << ' ' << a[i];
		}
		else{
			cout << ' ' << *nums.rbegin();
			nums.erase(*nums.rbegin());
		}
	}
	cout << '\n';
}

int main() {
	#ifndef ONLINE_JUDGE
	setIO("main");
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    while(n>0) {
    	solve();
    	n--;
    }
}