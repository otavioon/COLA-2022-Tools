#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
 
#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second
 
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, P> PP;
 
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
 
int n;
ll a[100000],b[100000],c[100000],cnt[100000];
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>b[i];
	REP(i,n) cin>>c[i];
	sort(a,a+n),sort(b,b+n),sort(c,c+n);
 
	int i=0;
	REP(j,n) {
		while (a[i]<b[j]&&i<n) i++;
		cnt[j]=i;
	}
	i=0;
	ll ans=0,sum=0;
	REP(j,n) {
		while (b[i]<c[j]&&i<n) {
			sum+=cnt[i];
			i++;
		}
		ans+=sum;
	}
	cout<<ans<<endl;
 
	return 0;
}