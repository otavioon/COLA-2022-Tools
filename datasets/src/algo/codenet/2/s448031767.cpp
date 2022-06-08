/*
	|\    /|        |       |
	| \  / |  ____  |___  . |
	|  \/  | |    | |   | | |_
	|	   | |    | |   | | |
	|	   | |____| |   | | |____|

*/


#include <bits/stdc++.h>
using namespace std;
#define printint(v) copy(begin(v), end(v), ostream_iterator<int>(cout," "))
#define printintv(s,e) copy(s,e, ostream_iterator<int>(cout," "))
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits (for ints only diff for ll)
//https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html for other in built
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
//#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef pair<int,int> p32; 
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
#pragma GCC optimize ("-O2")
const int LIM = 5e5+5, MOD = 1e9+7;
int t,n,m,k,x,y;
multiset<int> ss;
int arr[200005];
ll p2[40];

int main()
{
	IOS;
	cin>>n;
	p2[0]=1;
	forsn(i,1,40){
		p2[i]=2*p2[i-1];
	}
	forn(i,n){
		cin>>arr[i];
		ss.insert(arr[i]);
	}
	int ans=0;
	while(!ss.empty()){
		ll curr=*ss.rbegin();
		ss.erase(ss.find(curr));
		ll grt;
		forn(i,40){
			if(p2[i]>curr)
				{grt=p2[i];break;}
		}
		//dbg(grt),dbg(curr);
		if(ss.find(grt-curr)==ss.end())
			continue;
		ans++;
		ss.erase(ss.find(grt-curr));
	}
	cout<<ans<<ln;
}