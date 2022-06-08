/*
Author : farhan132
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef pair<ll , ll> lli;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;
typedef vector<lli> vlli;
typedef pair < ll , pair < ll , ll > > cm;

#define ff first
#define ss second
#define pb push_back
#define in insert
#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define f1(b) for(int i=1;i<=(b);i++)
#define f11(b) for(int j=1;j<=(b);j++)
#define f2(a,b) for(int i=(a);i<=(b);i++)
#define f22(a,b) for(int j=(a);j<=(b);j++)
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld", &a , &b)
#define pf(a) printf("%lld\n",a)
#define pff(a,b) printf("%lld %lld\n", a , b)
#define PI 3.14159265359
#define bug printf("**!\n")
#define mem(a , b) memset(a, b ,sizeof(a))
#define front_zero(n) __builtin_clzll(n)
#define back_zero(n) __builtin_ctzll(n)
#define total_one(n) __builtin_popcountll(n)
#define clean cout.flush()

const ll mod = (ll)1e9+7;
const ll maxn = (ll)1e5+10;
const int nnn = 664579+500;
const int inf = numeric_limits<int>::max()-1;
//const ll INF = numeric_limits<ll>::max()-1;
const ll INF = 1e18;

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};

//ofstream wr ("txt.txt");
//ifstream rr ("input.txt");


void solve(){
	
	ll n , k;
	cin >> n >> k;
	ll a[n+5];
	f1(n) cin >> a[i];
	ll lo = 0, hg = 1e9;
	ll ans = hg;
	while(lo <= hg){
		ll mid = (lo+hg)/2;
		ll tot = 0;
		if(mid != 0){
		for(ll i = 1; i <= n; i++){
			if(a[i] <= mid) continue;
			tot += ((a[i]/mid) + (a[i]%mid != 0))-1 ; 
		}
     	}else{
     	  
		   for(ll i = 1; i <= n; i++){
		   	if(a[i]!=0) tot  = INF;
		   }	
     		
		}
     	
		if(tot <= k) ans = min(ans , mid) , hg = mid-1;
		else lo = mid+1;
	}
	cout << ans;
 	return;
}

int main() {
   
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
    ll T;
    T=1;
    //cin >> T;
    //scanf("%lld",&T);
    ll CT = 0;
    
    //work();
    while(T--){
    	//cout << "Case #" << ++CT <<": " ;
    	//printf("Case %lld: ",++CT);
		solve();
	}
	
    return 0;
}
/*


*/