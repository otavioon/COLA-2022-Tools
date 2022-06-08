#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	sort(ALL(a));
	unordered_map<ll, ll> ma;
	REP(i, n) ma[a[i]]++;
	ll ans = 0;
	for(ll i = n - 1; i >= 0; i--) {
		if(ma[a[i]] == 0) continue;
		ma[a[i]]--;
		for(ll j = 2; j <= 2000000020; j *= 2) {
			if(j > a[i]) {
				if(ma[j - a[i]] > 0) {
					ma[j - a[i]]--;
					ans++;
				}
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */
