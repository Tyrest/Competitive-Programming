#include <bits/stdc++.h>
using namespace std;
#define fo(i,n)     for(i=0;i<n;i++)
#define Fo(i,k,n)   for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define foa(x,a)    for(auto&x:a)
#define ll long long
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(x)   printf("%s\n",x)
#define deb(x) cout << #x << ": " << x << '\n'
#define deb2(x, y) cout << #x << ": " << x << "," << #y << ": " << y << '\n'

void setIO(string s) {
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int main() {
    #ifndef ONLINE_JUDGE
    setIO("main");
    #endif

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int i, j, n, m, x, y;
    ll a,b,c,d;

    si(n);
    fo(i,n){
        cin>>a>>b>>c;
        d=((c-1)%a)*b+((c-1)/a+1);
        pl(d);
    }
}