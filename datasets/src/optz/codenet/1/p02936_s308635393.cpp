#include <bits/stdc++.h>
using namespace std;
 
//krishrawat
 
 
//----------------------------MACROS-------------------------------------------------
#define pb insert//                                                                 |
#define eb emplace_back//                                                           |
#define ff first//                                                                  |
#define ss second//                                                                 |
typedef long long int ll;//                                                         |
typedef long double ld;//                                                           |
#define all(a) a.begin(), a.end()//                                                 |
#define show(x) cerr << #x << " is " << x << "\n"//                                 |
#define show2(x, y) cerr << #x << " " << #y << " " << x << " " << y << "\n"//       |
typedef vector<ll> vl;//                                                            |
typedef vector<vl> vvl;//                                                           |
typedef pair<ll, ll> pp;//                                                          |
typedef vector<pp> vp;//                                                            |
typedef map<pp, ll> ipi;//                                                          |
typedef map<pp, char> ipc;//                                                        |
typedef map<ll, ll> ii;//                                                           |
typedef set<ll> sl;//                                                               |
typedef multiset<ll> msl;//                                                         |
typedef map<char, ll> ci;//                                                         |
typedef set<pair<ll, ll>> sp;//                                                     |
const ll mod = 1e9 + 7;//                                                           |
const ll N = 2e5 + 1;//                                                             |
//----------------------------------------------------------------------------------

vl grp[N];
vl ans(N,0);
vl val(N,0);
vl vis(N,0);

void dfs(ll x,ll adds){
    ans[x]=adds+val[x-1];
    for(auto i:grp[x]){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,ans[x]);
        }
    }
}

void solve()
{   
    ll n,q;cin>>n>>q;
    for(int i=0;i<n-1;i++){
        ll x,y;cin>>x>>y;
        grp[x].eb(y);
        grp[y].eb(x);
    }
    while(q--){
        ll a,b;cin>>a>>b;
        val[a-1]+=b;
    }
    
    vis[1]=1;
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    ll t; t=1;
    //cin>>t;
    while(t--) solve(); return 0;
}