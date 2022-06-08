#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 105

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unordered_map<int,int> umii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

mt19937 g1(time(0));

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

char s[MAXN];
int len,K,cnt;

int main(){
	scanf("%s %d",s+1,&K); len = (int)strlen(s+1);
	if(len == 1) return 0*printf("%d\n",K/2);
	for(int i=len; i>=2; i--)
		if(s[i] == s[i-1])
			cnt++, i--;
	if(s[1] == s[len]){
		int st = 0, e = 0, b = 0;
		for(int i=len; i>=3; i--)
			if(s[i] == s[i-1])
				st++, i--;
		for(int i=len-1; i>=2; i--)
			if(s[i] == s[i-1])
				e++, i--;
		for(int i=len-1; i>=3; i--)
			if(s[i] == s[i-1])
				b++, i--;
		printf("%lld\n",1LL*min({st+1,e+1,b+2})*K);
	}else printf("%lld\n",1LL*cnt*K);
}