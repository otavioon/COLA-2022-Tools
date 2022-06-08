#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define INF LONG_LONG_MAX
#define pb push_back
#define mp make_pair
#define MAXN 1000009
#define MOD 1000000007
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define left(x) x<<1
#define right(x) (x<<1)|1
#define PI acos(-1.0)
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<string,ll> msi;
typedef set<ll> si;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 
ordered_set;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> 
ordered_multiset;

int a[200005],n;

ll calc(ll x){
    ll res=0;
    for(int i=1;i<=n;++i)
        res+=abs(a[i]-i-x);
    return res;
}

ll solve(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    ll res=INF,low=-1e9,high=1e9;
    while(low<=high){
        ll mid=low+high;
        mid/=2;
        ll curr=calc(mid);
        res=min(res,curr);
        if(res==0)
            break;
        if(calc(low)<calc(high)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<res;
    return 0;
}

int main(){
    int T=1;
    //scanf("%d",&T);
    for(int i=1;i<=T;++i){
        solve();
    }
    return 0;
}