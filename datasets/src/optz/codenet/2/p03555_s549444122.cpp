#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#ifndef FAST_IO
 #define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);
#endif
#define FILE_IO freopen("input.txt","r",stdin)
#define int long long
#define f first
#define s second
#define endl '\n'
#define all(c) c.begin(),c.end()
#define debug(x) cerr << #x << " = " << x << endl;
const int MO=1e9+7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>void print(T t){for(auto &it:t)cout<<it<<" ";}
inline int powerexp(int a,int b,int m){int res=1;while(b){if(b&1)res=res*a%m;a=a*a%m,b>>=1;}return res%m;}
void solve(){
	string a,b;
	cin>>a>>b;
	reverse(all(a));
	cout<<(a==b?"YES":"NO")<<endl;
}
//-----------------------------
//comment from here for TOPCODER 
int32_t main(){
    IOS;
    solve();
    #ifdef LOCAL_DEFINE
    cerr<<"time elapsed "<<(double)clock()/CLOCKS_PER_SEC<<endl;
    #endif
}