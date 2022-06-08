#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <string>
#include <algorithm>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include "math.h"
#include "assert.h"

using namespace std;

#define ll long long

#define BUFF ios::sync_with_stdio(false)
#define epsilon 1e-07
#define pi 2 * acos(0.0);
#define mod 1000000007   // 1e9+7
#define cerr if(false)cerr
#define watch(x) cerr << #x << " = " << x << endl;

#define inf std::numeric_limits<ll>().max();

int main() {
	string s;
	ll k;
	cin >> s >> k;
	ll n = s.size();

	char c = s[n-1];
	ll i=0;
	while (i<n and s[i] == c) {
		i++;
	}
	ll q = i-1;
	i=n-1;
	while (i>=0 and s[i] == c) {
		i--;
	}
	ll l = i+1;

	// l - k.
	ll sa = q+1;
	ll sb = n-l;

	ll ans = 0;
	if (!sa or !sb or k==1) {
		string t = s;
		ll ct = 0;
		for(ll i=0; i<n; i++) {
			if (t[i] == t[i+1]) {
				t[i+1] = '@';
				ct++;
			} 
		}
		ans = ct * k;
	} else {
		if (sa == n) {
			ans = (n * k) / 2;
		} else {
			ans = sa / 2 + sb / 2 + (k-1)*(sa + sb) / 2;
			int ct = 0;
			for(int i=q+1; i<l; i++) {
				if (s[i] == s[i+1]) {
					s[i+1] = '@';
					ct++;
				} 
			}
			ans += ct*k;
		}	
	}

	cout << ans << endl;
}
