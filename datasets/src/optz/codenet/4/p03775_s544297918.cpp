#include "bits/stdc++.h"
#define int long long
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) 
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define endl '\n'
#ifdef LOCAL
#include "/home/iggaboi/Desktop/CP/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

int n;

int prods(int n){
    set<pair<int, int>> fac;
    for(int i = 1; i*i <= n; ++i){
        if(n%i == 0){
            fac.insert({i, n/i});
            // cout << i << " " << n/i << endl;
        }
    }
    int ret = -1;
    int out = 69;
    for(auto& x : fac){
        string a = to_string(x.first);
        string b = to_string(x.second);
        ret = max((int)a.length(), (int)b.length());
        out = min(out, ret);
    }
    return out;
}

void solve(){
    cin >> n;
    cout << prods(n) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
