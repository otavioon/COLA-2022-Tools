#include <iostream>
#include <algorithm>
#include <cmath>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define rep(i,x) for(int (i)=1;(i)<=(x);(i)++)
#define repp(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
#define forn(i,x) for(int (i)=0;(i)<(x);(i)++)
#define foreach(i,x) for(auto (i):(x))
using namespace std;
typedef pair<LL,int>pii;
int n;
pii a[200010];
int ans;
signed main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].first;
	sort(a,a+n);
	for(int i=n;i--;){
		if(a[i].second)continue;
		LL t=2LL<<__lg(a[i].first);
		int k=upper_bound(a,a+i,mp(t-a[i].first,0))-a;
		if(0<k&&k<=i&&a[i].first+a[k-1].first==t)ans++,a[k-1].second=1;
	}
	cout<<ans<<endl;
	return 0;
}
