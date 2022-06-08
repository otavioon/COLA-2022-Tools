#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define per(i,b,a) for(int i=b; i>=a; i--)
#define pb push_back
using namespace std;
typedef pair<int, int> pi ;
typedef vector<pair<int,int> > vpi ;
typedef vector<int> vi ;
typedef long long ll ;

const int maxn = 1e5 + 5 ;
const int inf = 1e9 + 5 ;
int n ;
vi gph[maxn] ;
int sz[maxn] ;
int ds[maxn], ret[maxn] ;
void dfs(int v, int p)
{
    bool chk = false ;
    for(auto u: gph[v])
    {
        if(u != p)
        {
            chk = true ;
            dfs(u,v) ;
            sz[v] += sz[u] ;
        }
    }
    if(!chk) sz[v] = 1 ;
}
void solve()
{
    rep(i,1,n)
     ds[sz[i]]++ ;
     int id = 1, pid = 1 ;
    rep(i,1,n)
    {
        if(id > n) break ;
        if(ds[i])
        {
           for(int k = id; k <= pid+ds[i]-1; k++)
           {
               ret[k] = i ;
               id++ ;
           }
           pid = id ;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cin >> n ;
    int par ;
    rep(i,1,n-1)
    {
        cin >> par ;
        gph[i+1].pb(par) ;
        gph[par].pb(i+1) ;
    }
    rep(i,0,n+1) sz[i] = 0, ds[i] = 0 ;
    dfs(1,0) ;
    solve() ;
    rep(i,1,n) cout << ret[i] << " " ;
    cout << "\n" ;
    return 0 ;
}
