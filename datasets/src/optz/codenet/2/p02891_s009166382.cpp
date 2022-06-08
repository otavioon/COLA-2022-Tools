
// Problem : 
// 			A - Connection and Disconnection
// 			Editorial
// 		
// Contest : AtCoder - AtCoder Grand Contest 039
// URL : https://atcoder.jp/contests/agc039/tasks/agc039_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,b,a) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
 
#define bug(x) cout<<#x<<"="<<x<<endl; 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ld pii=3.14159265359; 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200001; //check the limits, dummy
 ll ans=0;
void cr(string &str,int i)
{
	if(str[i-1]!=str[i])
		return;
	F0R(x,26)
	{
		if('a'+x!=str[i-1] && 'a'+x!=str[i+1])
		{
			str[i]='a'+x;
			ans++;
			return;
		}
	}
}
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);    
	string str;
	cin>>str;
	int K;
	cin>>K;
	int N=sz(str);
	if(N==1)
	{
		cout<<N/2;
		return 0;
	}
	FOR(x,1,N-1)
	{
		cr(str,x);
	}
	if(str[N-1]==str[N-2])
	{
		ans++;
		cout<<(K)*ans;
	}
	else if(str[N-1]==str[0])
	{
		ans++;
		cout<<(K)*ans-1;
	}
	else
		cout<<K*ans;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343