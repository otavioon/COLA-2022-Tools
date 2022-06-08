        // --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair<ll,ll>
#define vpii vector<pair<ll,ll> >
#define F first
#define S second
#define ld long double
#define built __builtin_popcountll
#define mst(a,i) memset(a,i,sizeof(a))
#define all(x) x.begin(),x.end()
#define itit(it,a) for(auto it=(a).begin(); it!=(a).end(); it++)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define repr(i,a,b) for(ll i=a; i>b; i--)
#define reprr(i,a,b) for(ll i=a; i>=b; i--)
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230
ll max3(ll x,ll y,ll z) {return max(max(x,y),z);}
ll min3(ll x,ll y,ll z) {return min(min(x,y),z);}
const ll M=2e5+10,M2=1e6+10,mod=1e9+7,inf=1e17+10;
void add(int& a, int b) {a+=b;if(a>=mod){a-=mod;}}
#define trace1(x)                  cerr<<#x<<": "<<x<<endl
#define trace2(x, y)              cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)              cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)          cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)     cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};
ll power(ll x,ll n){ll result=1;while(n>0){if(n%2==1)result=(result*x)%mod; x=((x%mod)*(x%mod))%mod;n=n/2;}return result;}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
	ll b[n+1];
	rep(i,1,n) cin >> b[i];
	ll a[n+1];
	a[n]=b[n-1];
	b[0]=inf;
	for(ll i=n-1; i>=1; i--){
		a[i]=min(b[i-1],b[i]);
	}
	ll ans=0;
	for(ll i=1; i<=n; i++) ans+=a[i];
	cout << ans;
    return 0;
}
/* The judge is never wrong! Your code is buggy
   Look for:
 * * Read the problem carefully.
 * * Don't forget to sort(), mod, ll!!!!
 * * Initial value = +/- infinity instead of zero!!!
 * * an easier and alternate approach
 * * read the problem statement carefully
 * * if concept is correct and still WA, try with a different implementation
 * * special cases (n=1?)
 * * if you have no idea just guess the appropriate well-known algorithm instead of doing nothing :/
 */
