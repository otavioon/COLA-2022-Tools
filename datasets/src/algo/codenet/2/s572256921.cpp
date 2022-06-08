#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#pragma 03
using namespace std;
using namespace __gnu_pbds;
ll n;
multiset <ll> st;
int main(){
	fastio;
	ll t, k, ans = 0;
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> t, st.insert(t);
	while (st.size() > 1){
		auto it = st.end();
		it--; t = *it;
		st.erase(it);
		for (k = 1; k <= t; k *= 2);
		it = st.find(k - t);
		if (it != st.end()){
			st.erase(it); ans++;
		}
	}
	cout << ans << endl;
}