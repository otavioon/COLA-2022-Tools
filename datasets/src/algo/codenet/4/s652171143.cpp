//----AUTHOR:kkdrummer----/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> P;
#define X real()
#define Y imag()
ld restant(P p){return abs(p);}
//polar(x,y) mag=l,arg=y
//typedef unordered_set<ll> usll;
//typedef unordered_multiset<ll> umsll;
typedef multiset<ll> msll;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll> > vpll;
typedef priority_queue<ll> pqll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
//typedef unordered_multiset<int> umsi;
//typedef unordered_set<int> usi;
typedef pair<int,int> pi;
typedef vector<pair<int,int> > vpi;
typedef vector<pair<double,double> > vpd;
typedef pair<double,double> pd;
typedef priority_queue<int> pqi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ind_set;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ind_setll;
#define in insert
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define be begin
#define en end
#define itr iterator
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mo 1000000007
#define inf 1000000000000000001
#define ninf -1000000000000000001
#define ima INT_MAX
#define imi INT_MIN
#define oncnt __builtin_popcount
#define zerobegin __builtin_clz
#define zeroend __builtin_ctz
#define parity __builtin_parity
#define all(x) x.be(),x.en()
#define eps 1e-9
const ld pii=3.14159265359;
inline ll modpow(ll x,ll n){if(n==0)return 1;if(n==1)return(x%mo);ll u=(modpow(x,n/2));u=(u*u)%mo;if(n%2!=0)u=(u*x%mo)%mo;return u;}
inline ll modinv(ll x){return modpow(x,mo-2);}
inline ll mmul(ll a,ll b){    if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}
inline ll madd(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a+b>=mo)return(a+b)%mo;return(a+b);}
inline ll msub(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;return((a-b+mo)%mo);}
inline ll mdiv(ll a,ll bb){if(a>=mo)a=a%mo;ll b=modinv(bb);if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}
inline ll gcd(ll a,ll b){return __gcd(a,b);}


int main()
{
io
int testcases=1;//cin>>testcases;
while(testcases--)
{	
int n;
cin>>n;
int d;
cin>>d;
si s;
for(int i=0;i<d;i++)
{
	int x;
	cin>>x;
	s.insert(x);
}

while(true)
{
	bool f=true;
	int k=n;
	while(k)
	{int r=k%10;
	if(s.find(r)!=s.end())
	{
		f=false;
		break;
	}
		k=k/10;
	}
	if(f)
	{
		cout<<n;
		break;
	}
	n++;
}

}return 0;}