#include <bits/stdc++.h>
using namespace std;
#define fo(i,n)		for(i=0;i<n;i++)
#define Fo(i,k,n)	for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define foa(x,a)	for(auto&x:a)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(x)	scanf("%s",&x)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(x)	printf("%s\n",x)
#define deb(x) cout << #x << ": " << x << '\n'
#define deb2(x, y) cout << #x << ": " << x << "," << #y << ": " << y << '\n'

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void solve() {
	int i, j, n, m, k, x, y;

	cin >> n;
	int a[n];
	fo(i,n){
		cin >> a[i];
	}
	sort(a,a+n);
	int c=0,max=0,last=1;
	foa(x,a){
		if(x==last){
			c++;
		}
		else{
			if(max<c) max=c;
			c=1;
			last=x;
		}
	}
	if(max<c) max=c;
	if(2*max-n<0) pi(n%2);
	else pi(2*max-n);
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