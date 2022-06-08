#include<bits/stdc++.h>
 
#define pb push_back
// #define mp make_pair
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define hell1 1000000007
#define hell2 1000000009
#define pi 3.1415926535
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ll long long
#define ld long double 
#define no_of_digits(n) floor(log10(n)) + 1
#define deb(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "\t" << #y << "=" << y << endl;
#define deb3(x, y, z) cout << #x << "=" << x << "\t" << #y << "=" << y << "\t" << #z << "=" << z << endl;
#define INF 1e9
#define LL_MAX 1e18
// memset(array, -1, sizeof(array[0][0]) * row * count)
using namespace std;
 
ll mult(ll a,ll b, ll p=hell1){   return ((a%p)*(b%p))%p; }
ll multbig(ll a,ll b,ll mod=hell1){   if(a==0 or b==0) return 0;if(a==1 or b==1) return (a*b)%mod;ll cur=multbig(a,b/2,mod);cur=(2*cur)%mod;if(b%2) cur=(cur+a)%mod;return cur;}
ll add(ll a, ll b, ll p=hell1){ if(a>=p) a%=p; if(b>=p) b%=p; if(a+b>p) return (a + b)%p; else return a+b;}
ll sub(ll a, ll b, ll p=hell1){return (a%p - b%p + p)%p;}
ll fpow(ll n, ll k, ll p = hell1) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = mult(r,n,p); n = mult(n,n,p);} return r;}
ll inv(ll a, ll p = hell1) {return fpow(a, p - 2, p);}
ll inv_euclid(ll a, ll m = hell1){ll m0 = m;ll y = 0, x = 1;if (m == 1)return 0;while (a > 1){ll q = a / m;ll t = m;m = a % m, a = t;t = y;y = x - q * y;x = t;}if (x < 0)x += m0;return x;}
int isPowerof2(ll x) { return (x && !(x & x-1)); } 
ll log2(ll x) { ll res = 0; while (x >>= 1) res++; return res; } 
bool isPerfectSquare(long double x) {long double sr = sqrt(x); return ((sr - floor(sr)) == 0); }
bool check(ll i,ll j,ll n){return (i>=0 && i<n && j>=0 &&  j<n);} //matrix boundary checking
 
// template<typename... T>
// void read(T&... args) {
//     ((cin >> args), ...);
// }
 
// template<typename... T>
// void write(T&&... args) { //rvalue reference is new to C++ 
//     ((cout << args << " "), ...);
// }
 
 
ll ceil(const ll &a, const ll &b){return (a - 1)/b + 1;}
 
// max({a, b, c, d})
// cout << fixed for removing e notation
 
bool comp(tuple<ll, string, string>a, tuple<ll, string, string>b)
{
    if(get<0>(a) > get<0>(b)) return true;
    return false;
}
 
void convert(int arr[], int n) 
{ 
    int temp[n+1];
    for(int i=1;i<=n;i++)
        temp[i] = arr[i]; 
    // memcpy(temp, arr, n*sizeof(int)); 
  
    sort(temp+1, temp+n+1);   
    unordered_map<int, int> umap;
    int val = 1; 
    for (int i = 1; i <= n; i++) 
        umap[temp[i]] = val++;
    for (int i = 1; i <= n; i++) 
        arr[i] = umap[arr[i]]; 
}
 
bool prime[10000005];
void SieveOfEratosthenes(int n) 
{
    memset(prime, true, sizeof(prime)); 
    prime[0] = prime[1] = 0;
    for (int p=2; p*p<=n; p++) 
    {
        if (prime[p] == true) 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
    }
}

bool comp1(pair<int, int>&a, pair<int, int>&b)
{
    if(a.se <= b.se) return 1;
    else return 0;
}
 
int main()
{
    int k, x;
    cin >> k >> x;

    if(k*500 >= x) cout << "Yes\n";
    else cout << "No\n";
}
