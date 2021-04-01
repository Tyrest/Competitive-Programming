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

	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	if (s1.size() > s2.size()){
		string temp = s2;
		s2 = s1;
		s1 = temp;
	}
	int l=s1.size()+1;
	bool found=false;
	while(!found&&l>0){
		l--;
		fo(i,s1.size()-l+1){
			if(s2.find(s1.substr(i,l))!=string::npos){
				found=true;
				break;
			}
		}
	}
	pi(s1.size()+s2.size()-2*l);
}

int main() {
	#ifndef ONLINE_JUDGE
	setIO("main");
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    string s1;
    getline(cin,s1);

    while(n>0) {
    	solve();
    	n--;
    }
}