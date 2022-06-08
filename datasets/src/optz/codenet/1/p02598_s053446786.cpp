#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define clr(x) memset(x, 0, sizeof(x))
#define all(a) a.begin(),a.end()
#define forn(i, a,b) for(int i = int(a); i < int(b); ++i)
#define forn_r(i, b, a) for(int i = int(b); i > int(a); i--)
#define trav(a,x) for (auto& a : x)
#define printArray(array, length) for(int i = 0; i < length; i++) cout<< array[i] << (i == length - 1 ? '\n' : ' '); 
#define print(x) cout << x << '\n'
#define print2(x, y) cout << x << ' ' << y << '\n'
#define debug(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
 
using namespace std;
typedef long long ll; 
const int INF = 0x3f3f3f3f;
const ll LNF  = 0x3f3f3f3f3f3f;
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline ll  gcd(ll  a, ll  b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
 
bool possi(ll mid, vector<ll> a ,ll k){
	for(auto x:a){
		k-=(x+mid-1)/mid -1;
	}
	return k>=0;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t =1;
    //cin>>t;
    while(t--){
    	ll n, k; cin>>n>>k;
    	vector<ll> a(n);forn(i,0,n) cin>>a[i];
    	
    	ll mini =1, maxi =1e9+1;
    	ll mid;
    	while(mini!=maxi){
    		mid = (mini+maxi)/2;
    		if(possi(mid,a,k)){
    			maxi=mid;
    		}
    		else{
    			mini=mid+1;
    		}
    		
    	}
    	print(maxi);
       	 
    }
    return 0;
}