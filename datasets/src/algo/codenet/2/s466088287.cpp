#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
using ll = int64_t;
template<typename T>
using vec = vector<T>;
using P = pair<ll, ll>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[5001][5002];


signed main(){
	IOS;
	ll n;
	cin >> n;
	multiset<ll,greater<ll>> a;
	REP(i,n){
		ll x;
		cin >> x;
		a.insert(x);
	}
	ll ans = 0;
	for(auto it = a.begin();it != a.end();){
		ll div = 2;
		while(*it / div > 0)div *= 2;
		auto i = a.find(div - *it);
		if(i == a.end()){
			it++;
			continue;
		}
		a.erase(i);
		a.erase(it++);
		ans++;
	}
	dump(ans);
}