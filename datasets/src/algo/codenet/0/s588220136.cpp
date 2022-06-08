#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll k;
	cin >> s >> k;
	ll n = s.size();
	s += s;
	
	ll ans1 = 0;
	ll ans2 = 0;
	bool flag = false;
	for(ll i = 0; i < 2*n; i++){
		if(i == 2*n-1){
			if(s[i] == s[0]){
				ans2++;
				if(k%2 == 0){flag = true;}
			}
		}
		else{
			if(s[i] == s[i+1]){
				if(k%2 == 1 && i == n-1){flag = true;}
				if(i < n){ans1++;}
				else{ans2++;}
				i++;
			}
		}
	}
	
	if(k%2 == 0){
		ll ans = ans1*(k/2)+ans2*(k/2);
		if(flag){ans--;}
		print(ans)
	}
	else{
		ll ans = ans1*(k/2+1)+ans2*(k/2);
		if(flag){ans--;}
		print(ans)
	}
	return 0;
}