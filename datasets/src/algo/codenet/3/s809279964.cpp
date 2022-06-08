#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
const int N=100000;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,ans=0;
	ll a[N],b[N],c[N],ap,bp,cp;
	cin >> n;
	FOR(i,0,n)cin >> a[i];
	FOR(i,0,n)cin >> b[i];
	FOR(i,0,n)cin >> c[i];
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	ap=bp=cp=n-1;
	while(cp>=0){
		while(b[bp]>=c[cp]){
			bp--;
		}
		while(a[ap]>=b[bp]){
			ap--;
		}
		ans += (ap+1)*(bp+1);
		cp--;
	}
	cout << ans << endl;
	return 0;
}