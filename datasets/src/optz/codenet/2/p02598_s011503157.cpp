//***********************
//Author:kibi11
//Quarantine Days
//***********************

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define N 2e5+1
#define MOD 1000000007
#define dd double
#define fr(i, n) for(int i = 0; i < n; i++)
#define fr1(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,k) for(int i=a;i>=k;i--)
#define same int t;cin>>t;while(t--)
#define check(x) cout << (#x) << " is " << (x) << endl;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define f first
#define s second
#define XOX
#define pi = 3.14159265358979323846

//////////////////////////////////////////////////////////////////////////
/////////////////DEBUGING ZONE//////////////////////////////

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
///////////////////////////////////////////////////////////////////////////
 
ll powermod(ll base, ll exp, ll mod) {
	ll result = 1;
	while (exp != 0) {
		if ((exp % 2) == 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return result;
}

///////////////////////////////////////////////////////////////////////////
//Fuctions if any:
std::vector<ll> v(N);
ll n;
bool see(ll mid,ll k)
{
	ll count=0;
	fr(i,n)
	{
		count+=(v[i]-1)/mid;
	}
	// cout<<count<<endl;
	return count<=k;
}





///////////////////////////////////////////////////////////////////////////
int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int tt = clock();
//ios_base& scientific (ios_base& str);
ll k;
cin>>n>>k;
// vector<int> v(n);
fr(i,n) cin>>v[i];
ll min=0;
ll max=*max_element(v.begin(), v.end());
ll mid;
while(min!=max)
{
	
	mid=(min+max)/2;
	// debug(min,max,mid);
	if(see(mid,k))
	{
		max=mid;
	}
	else
	{
		min=mid+1;
	}
	// debug(min,max,mid);

}
cout<<max<<endl;
cerr << "TIME = " << (double) 1.0 * (clock() - tt) / CLOCKS_PER_SEC << " seconds" << endl;
return 0;
}