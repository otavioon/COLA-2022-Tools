#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string s;
int k,f[1000005][2],ans=1e18;
int solve(string t){
	f[0][0]=0;f[0][1]=1;
	for(int i=1;i<t.size();i++){
		f[i][0]=min(f[i-1][1],f[i-1][0]+(t[i]!=t[i-1]?0ll:(ll)1e18));
		f[i][1]=min(f[i-1][1],f[i-1][0])+1;
	}
	return min(f[(int)t.size()-1][0],f[(int)t.size()-1][1]);
}
signed main(){
	cin>>s>>k;
	string t="";
	if(k<=200){
		for(int i=1;i<=k;i++)t+=s;
		cout<<solve(t)<<endl;
		return 0;
	}
	for(int i=1;i<=100;i++)t+=s;
	int ans=solve(t);
	t+=s;
	int ans2=solve(t);
	cout<<ans+(k-100)*(ans2-ans)<<endl;
	return 0;
}