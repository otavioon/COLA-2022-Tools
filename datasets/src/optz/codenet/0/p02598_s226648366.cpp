#include<bits/stdc++.h> 
using namespace std;
#define se second
#define fr first
#define int  long long int
#define pb push_back
#define inf 1e18
#define slld(x) scanf("%lld",&x)
#define plld(x) printf("%lld\n",x)
#define all(v) v.begin(),v.end()
#define CHAL_BAAP_KO_MT_SIKHA ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define MOD 998244353
#define endl "\n" 
/*
    Damn Fast:TheFuckinMastermind
    while(How to solve the Question?){
                Read the Question Again!!
           }
        do
            Practise
    #Motivation::::0/0  
*/
const int N=5e5;
vector<int> seg[4*N+1];
int a[N+1],ans[N+1];
vector<int> merge(vector<int> v1,vector<int> v2){
    int i=0,j=0;
    vector<int> v;
    while(i<v1.size() and j<v2.size()){
        if(v1[i]<v2[j]){
            v.pb(v1[i]);
            i++;
        }
        else{
            v.pb(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        v.pb(v1[i]);
        i++;
    }
    while(j<v2.size()){
        v.pb(v2[j]);
        j++;
    }
    return v;
}
void build(int l,int r,int idx){
    if(l==r){
        seg[idx].pb(ans[l]);
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*idx+1);
    build(mid+1,r,2*idx+2);
    seg[idx]=merge(seg[2*idx+1],seg[2*idx+2]);
}
int qury(int l,int r,int ll,int rr,int idx){
    if(l>rr or r<ll)
        return 0;
    if(ll<=l and rr>=r){
        return (lower_bound(seg[idx].begin(),seg[idx].end(),ll)-seg[idx].begin());
    }
    int mid=(l+r)/2;
    return qury(l,mid,ll,rr,2*idx+1)+qury(mid+1,r,ll,rr,2*idx+2);
}
signed main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin); 
    // freopen("out.txt","w",stdout);
    // #endif  
    CHAL_BAAP_KO_MT_SIKHA
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int l=1,r=mx;
    int ans;
    while(l<=r){
        int mid=(l+r)/2;
        int count=0;
        for(int i=1;i<=n;i++){
            if(a[i]>mid){
                count+=ceil(1.0*a[i]/mid)-1;
            }
        }
        if(count<=k){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
}