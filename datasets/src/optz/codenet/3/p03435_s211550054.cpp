#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define MAX 1000000000000000
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revrep(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define ii pair<ll,pair<ll,ll> >
#define MP make_pair
#define pb push_back
#define f first
#define se second
#define ll long long int
#define vi vector<ll>
ll modexp(ll a,ll b){ ll res = 1; while(b > 0){  if(b & 1) res = (res * a)%mod;  a = (a * a)%mod;  b/=2;  }  return res; }
#define rs resize
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > OST;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

const ll N = 3;
ll i,j,k,l,s;
bool f;
ll a[N][N],c[N],m[N],d[N];
int main()
{
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    rep(i,0,N) rep(j,0,N) cin>>a[i][j],m[i] = max(m[i],a[i][j]);
    rep(i,0,m[0] + 1) rep(j,0,m[1] + 1) rep(k,0,m[2] + 1){
        d[0] = i; d[1] = j; d[2] = k;
        rep(l,0,N)
            c[l] = a[0][l] - i;
        f = 1;
        for(l = 1;l < N and f;l++){
            rep(s,0,N) if(a[l][s] - d[l] != c[s]){
                f = 0;
                break;
            }
        }
        if(f){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}