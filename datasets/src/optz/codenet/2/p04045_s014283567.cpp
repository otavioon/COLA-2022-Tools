#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long int>> vvl;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
typedef vector<pair<int, int>> vii;
typedef vector<pair<long long int, long long int>> vll;
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test() long long int t; cin >> t; cin.ignore(); while(t--) 
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define MOD 1000000007
#define SMOD 998244353
#define pq priority_queue
#define all(x) x.begin(),x.end()
#define SP(x) setprecision(x)
#define sp " "
#define inp(a) ll a;cin>>a;cin.ignore()
#define inps(a,b) ll a,b;cin>>a>>b;cin.ignore()
#define out(a) cout<<SP(20)<<a<<'\n'
#define outs(a,b) cout<<SP(20)<<a<<" "<<b<<'\n'
#define ins insert
#define er erase
#define lb lower_bound
#define ub upper_bound
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define inpa(a,n) ll a[n]; for(int i=0; i<n; i++){cin>>a[i];}
#define inpv(a,n) vl a; for(int i=0; i<n; i++){inp(x);a.pb(x);}
#define outa(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}cout<<'\n';
#define outv(v) for(auto i:v){cout<<i<<" ";}cout<<'\n';
set<char> vow = {'a','e','i','o','u','A','E','I','O','U'};
ll xpow(ll n, ll m){if(m==0){return 1;}else{ll x = xpow(n, m/2);if(m&1){return x*x*n;}else{return x*x;}}}
ll xmod(ll a, ll m){return (((a%m)+m)%m);}
ll xmodpow(ll n, ll m, ll y){if(m==0){return 1;}else{ll x = xmodpow(n, m/2, y);if(m&1){return xmod((xmod((xmod(x,y)*xmod(x,y)),y)*xmod(n,y)),y);}else{return xmod((xmod(x,y)*xmod(x,y)),y);}}}
 
int main(){
    fast();
 
/* you get what you work for not what you wish for */
    
    inps(n, k);
    vector <bool> a(10, 1);
    for(int i=0; i<k; i++){
        ll x;
        cin >> x;
        a[x] = 0;
    }
    for(ll i=n; ; i++){
        ll j = i;
        bool check = 1;
        while(j){
            ll x = j%10;
            j/=10;
            if(!a[x]){
                check = 0;
            }
        }
        if(check){
            cout << i << endl;
            return 0;
        }
    }
}