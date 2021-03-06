/*######################################################
#########~~~~~####~~~~###~~##~~##~~##~~##~~##~~#########
#########~~##~~##~~##~~##~~~#~~##~~~#~~##~~##~~#########
#~~~~~~##~~~~~###~~~~~~##~~#~~~##~~#~~~##~~##~~##~~~~~~#
#########~~######~~##~~##~~##~~##~~##~~##~~##~~#########
#########~~######~~##~~##~~##~~##~~##~~###~~~~##########
######################################################*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3")
#define rtn return
#define endl '\n'
#define F first
#define S second
#define mt make_tuple
#define pb push_back
#define MOD 1000000007
#define INF 1e18
#define EPS 1e-15
#define int long long
#define value_at find_by_order
#define index_of order_of_key
#define fill(a, v) memset(a,v,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i, n) for(int i=0;i<(int)n;++i)
#define per(i, n) for(int i=(int)n-1;i>=0;--i)
#define loop1(i, n) for(int i=1;i<=(int)n;++i)
#define loop(i, begin, end) for(int i=(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " = " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " = " << arg1 << " |";
  __f(comma+1, args...);
}
#else
#define trace(...)
#endif

typedef string str;
typedef pair<int, int> pll;
typedef vector<int> vll;
typedef vector<pll> vpll;	
typedef long double db;

template<class T, class V> void remin(T &a, V b) { a > b ? a = b : a = a; }
template<class T, class V> void remax(T &a, V b) { a < b ? a = b : a = a; }
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define N 100005

//

int32_t main() {
	FAST_IO;
	
	int n, d;
	cin >> n >> d;
	int ans = 0;
	for (int i = 1 + d; ; i += 2*d + 1) {
		ans++;
		if (i >= n - d) break;
	}
	cout << ans;
	rtn 0;
}
