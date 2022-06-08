#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

#define ll long long int
#define ld long double
#define bigint int64_t
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;read(t);while(t--)
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>

/*#include <ext/pb_ds/assoc_container.hpp> // Policy_based_Data_Structure 
#include <ext/pb_ds/graph_policy.hpp> 
using namespace __gnu_pbds;*/ 

#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))

using namespace std;
template <typename T>
void read(T &x){
    cin >> x;
}
template <typename T , typename T0>
void read(T &x,T0 &y){
    cin >> x >> y;
}

template <typename T , typename T0 , typename T1>
void read(T &x,T0 &y,T1 &z){
    cin >> x >> y >> z;
}

template <typename T , typename T0 , typename T1 , typename T2>
void read(T &x,T0 &y,T1 &z,T2 &w){
    cin >> x >> y >> z >> w;
}

template <typename T , typename T0>
void read(pair< T , T0 > &p){
    cin >> p.fst >>p.scd;
}

template <typename T>
void read(vector< T > &oneD,ll n){
    forn(i,n)
    {
        ll x;
        read(x);
        oneD.push_back(x);
    }
}

template <typename T>
void read(T oneD[] , ll n){
    for(ll i=0;i<n;i++){
        read(oneD[i]);
    }
}

template <typename T>
void write(T &x){
    
    cout << x << " ";
}

template <typename T , typename T0>
void write(T &x,T0 &y){
    cout << x << " " << y << "\n";
}

template <typename T , typename T0 , typename T1>
void write(T &x,T0 &y,T1 &z){
    cout << x << " " << y << " " << z << "\n";
}

template <typename T , typename T0 , typename T1 , typename T2>
void write(T &x,T0 &y,T1 &z,T2 &w){
    cout << x << " " << y << " " << z << " " << w << "\n";
}

template <typename T , typename T0>
void write(pair< T , T0 > &p){
    write(p.fst);
    write(p.scd);
    cout << endl;
}

template <typename T>
void write(vector< T > &oneD){
    for(ll i=0;i<oneD.size();i++){
        write(oneD[i]);
    }
    cout << endl;
}

template <typename T>
void write(T oneD[] ,int n){
    for(ll i=0;i<n;i++){
        write(oneD[i]);
    }
    cout << endl;
}

template <typename T , typename T0>
void write(map< T , T0 > &mpp){
    for(auto it : mpp){
        write(it.fst);
        cout << ": ";
        write(it.scd);
        cout << "\n";
    }
    cout<<endl;
}

vll seive;
void Seive(){
    const ll maxn = 3000005;
    seive.resize(maxn);
    forn(i,maxn) seive[i] = i;
    seive[1] = -1;
    seive[0] = -1;
    forab(i,2,maxn,1) if(i == seive[i]) for(ll j = 2*i ; j < maxn ; j+=i) if(seive[j] == j) seive[j] = i;
}

ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1; 
    y = x1;
    return gcd;
}

ll modinv(ll a , ll mod = MOD){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}

//Chinese Remainder Theoram
ll find_x_CRT(ll num[],ll rem[],ll n)
{
    ll pro=1;
    forn(i,n)
    pro*=num[i];
    ll res=0;
    forn(i,n)
    {
        ll pp = pro/num[i];
        res+=(rem[i]*modinv(pp,num[i])*pp);
    }
    res%=pro;
    return res;
}

ll power(ll a, ll b, ll m = MOD) {
    a%=m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %m;
        a = a * a %m;
        b >>= 1;
    }
    return res;
}

ll powe(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

string getString(char x) 
{ 
    string s(1, x); 
    return s;    
} 

//typedef graph<ll, null_type, less<ll>, rb_graph_tag,graph_order_bigsmallistics_node_update> index_set


/* //Graph basic template
const ll maxn = 2e5+5;
vector<vector<ll>> ad(maxn);
vector<bool> vis(maxn);
void add_edge(ll u,ll v)
{
    ad[u].pb(v);
    ad[v].pb(u);
}*/

int main ()
{
    flash;
    ll n,d;
    read(n,d);
    ll x = 2*d+1;
    ll y = 0,ans=0;
    while(y<n)
    {
        y+=x;
        ans++;
    }
    cout<<ans;
    return 0;
}

