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

	cin >> n >> k;
	string s1;
	getline(cin, s1);
	getline(cin, s1);
	if(s1.find('*')==s1.rfind('*')){
		pi(1);
		return;
	}
	s1[s1.rfind('*')]='x';
	i=s1.find('*')+k;
	int c=2;
	while(i<s1.size()&&s1[i]!='x'){
		if(s1[i]=='*'){
			i+=k;
			c++;
		}
		else{
			i--;
		}
	}
	pi(c);
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