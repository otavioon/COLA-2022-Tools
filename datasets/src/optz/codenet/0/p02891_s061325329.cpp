#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VL vector<ll>
# define PII pair<int,int> 
# define VII vector<PII>
# define mp make_pair
# define pb push_back
# define vt vector
# define PI acos(-1)
# define ld long double
# define endl "\n"
# define all(c) (c).begin(), (c).end()
# define ft first 
# define sd second 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i) 
# define F0R(i,b) for(int i = 0 ; i < b ; ++i) 

const ll inf = 1e18 ; 
const int MxN = 100001 ; 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	
	string s ; 
	int k ; 
	cin >> s >> k ; 
	int n = s.size() ; 
	ll cnt = 1 ,moves=0; 
	bool ok = false , ok2 = false; 
	char prv = s[0] ; 
	bool first = true ; 
	bool last = 0 ; 
	for(int i=1; i<n ; ++i) {
		if(s[i] == prv) {
			cnt++;
		} else {
			if(i==n-1) { 
				ok = true ; 
				if(cnt % 2 == 0 ) 
					last = 1 ; 
				else 
					last = 0 ; 
			}
			if(first) {
				if(cnt % 2 == 0) 
					ok2 = true ; 
				else ok2 = false ; 
				first = false ; 
			}
			moves += cnt/2 ; 
			cnt = 1 ; 
			prv = s[i] ; 
		}
	}
	if(!ok) {
		if(cnt == n) {
			cout << (cnt*k) /2 ;
			return 0 ; 
		}
		moves += cnt/2 ; 
		if(cnt % 2 == 0 ) 
					last = 1 ; 
				else 
					last = 0 ;
	}
	ll ans = moves * k ; 
	if(s[0] == s[n-1]) {
		if(!ok2 && !last)
			ans += k -1 ; 
	}
	
	cout << ans ; 

	return 0 ; 
}


