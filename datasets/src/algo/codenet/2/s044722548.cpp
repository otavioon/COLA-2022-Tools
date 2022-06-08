#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int nxt(int x){
    int b = 1;
    while(b < x) b <<= 1;
    return b;
}

int main() {
	fastio;
	
    int n, res = 0; cin >> n;
    multiset<int> s;
    forn(i,n){
        int x; cin >> x;
        s.insert(x);
    }
    while(!s.empty()){
        auto x = prev(s.end());
        int e = nxt(*x)-*x;
        auto y = s.lower_bound(e);
        if(y != s.end() && y != x && *y == e) res++, s.erase(y);
        s.erase(x);
    }
	cout << res << endl;
	return 0;
}
