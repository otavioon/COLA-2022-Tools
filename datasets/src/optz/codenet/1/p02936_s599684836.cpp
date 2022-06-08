#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long int ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
const int MOD=1000000007;
#define pp pair<ll,ll>
bool isPowerOfTwo (ll x)  
{  
    return x && (!(x&(x-1)));  
}
bool isPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}
int highestPowerof2(unsigned int n) 
{ 
    // Invalid input 
    if (n < 1) 
        return 0; 
  
    int res = 1;
    for (int i=0; i<8*sizeof(unsigned int); i++) 
    { 
        int curr = 1 << i; 
        if (curr > n) 
           break; 
  
        res = curr; 
    } 
  
    return res; 
} 
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,-1,0,1,1,-1,-1,1};
/*lcm(gcd(N1, M), gcd(N2, M), ..., gcd(Nk, M)) = gcd(lcm(N1, ..., Nk), M)
gcd(lcm(N1, M), lcm(N2, M), ..., lcm(Nk, M)) = lcm(gcd(N1, ..., Nk), M).

If gcd(N1, N2) = 1, then
gcd(N1·N2, M) = gcd(N1, M)·gcd(N2, M)
lcm(N1·N2, M) = lcm(N1, M)·lcm(N2, M)/M.

lcm(M, N, P) · gcd(M, N) · gcd(N, P) · gcd(P, M) = NMP · gcd(N, M, P).
*/
////////////////////////////////////////////////////////////////////
const int maxn=1e5 + 10;
ll ans[maxn];
vector<ll> adj[maxn];
bool vis[maxn];
void dfs(ll x,ll p)
{
    vis[x]=true;
    ans[x]+=ans[p];
    for(auto i:adj[x])
    {
        if(!vis[i])
        {
            dfs(i,x);
        }
    }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  cout.tie(NULL);
  int t=1;
  while(t--)
  {
    ll n,q;
    cin>>n>>q;
    ll a,b;
    REP(i,n-1)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    REP(i,q)
    {
        cin>>a>>b;
        ans[a]+=b;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  }  
  return 0;
}
/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( )
* special cases (n=1?)
* 1LL<<i and not 1<<i
* overflow (int vs ll?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/