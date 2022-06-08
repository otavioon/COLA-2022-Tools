#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define speed() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
// #define exit(a, b) return cout << a, b;

#define loop(i,a,b) for(ll i=a;i<b;i++)
#define all(v) v.begin(), v.end() 

#define print(stuff) cout << stuff << endl
#define printc(stuff) for(auto x: stuff) cout << x << " "; cout << endl;
#define printPrec(stuff) cout << fixed << setprecision(15) << stuff << endl;
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;
#define len length
#define ret0 return 0
#define ret return 

#define ll long long
#define ld long double
#define fi first
#define endl '\n'
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fill(ar, x) memset(ar, x, sizeof ar)

#define vl vector<ll> 
#define sl set<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll> 
#define pq priority_queue<ll>

// typedef tree<ll,null_type,less<ll>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;

#define inf (long long int) 1e18
#define eps 0.000001
#define mod 1000000007
#define mod1 998244353
#define MAXN (ll)1e5+5

vl adj[2*MAXN];
ll val[2*MAXN]={0};
ll ans[2*MAXN]={0};

void dfs(ll s, ll e){
    ans[s] += val[s];
    for(auto x: adj[s]){
        if(x!=e){
            ans[x]+=ans[s];
            dfs(x, s);
        }
    }
}

void solve(){
    ll n,q;
    cin>>n>>q;
    loop(i,0,n-1){
        ll a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    loop(i,0,q){
        ll p, x;
        cin>>p>>x;
        val[p]+=x;
    }
    dfs(1, 0);
    loop(i,1,n+1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
        
    
}

