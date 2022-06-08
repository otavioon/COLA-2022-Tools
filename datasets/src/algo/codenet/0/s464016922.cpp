#include <bits/stdc++.h>
  
using namespace std;
  
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
  
#define pb push_back
#define mp make_pair
#define cotu cout
#define itn int
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
  
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
  
const ll inf = int(1e9);
const ll mod = inf + 7;
const int N = 1e6 + 555;
const double PI = acos(-1.0);
ll ok[N];
void solve()
{
	string s;
	cin >> s;
	ll k;
	cin >> k;
	if(sz(s) == 1){
		cout << k - 1 << endl;
	}
	else if(sz(s) == 2){
		if(s[0] == s[1]) cout << k;
		else cout << 0;
	}
	else{
		ll cnt = 0;
		if(s[sz(s) - 1] != s[0]){
			for(int i = 0; i < sz(s) - 1; ++i){
				if(!ok[i] && s[i] == s[i + 1]) ok[i] = 1, ok[i + 1] = 1, cnt++;
			}
			cout << cnt * (k) << endl;
			return;
		}
		if(s[sz(s) - 1] == s[sz(s) - 2]){
			ok[sz(s) - 1] = 1;
			for(int i = sz(s) - 2; i >= 1; --i){
				if(!ok[i] && s[i] == s[i - 1]) ok[i - 1] = 1, cnt++;
			}
			cout << cnt * k + k << endl; 
		}else{
			for(int i = 0; i < sz(s) - 1; ++i){
				if(!ok[i] && s[i] == s[i + 1]) cnt++, ok[i + 1] = 1;
			}
			cout << cnt * k + k - 1;
		}

	}
}
  
int main()
{
    Red;
    // prec();
    solve();
    return 0;
}