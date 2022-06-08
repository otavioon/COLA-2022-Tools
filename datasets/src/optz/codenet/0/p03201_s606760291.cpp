
 #include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_intで宣言
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////


int main(){
    ll n;cin>>n;
    ll qq[n];rep(i,0,n-1)cin>>qq[i];
    sort(qq,qq+n);
    vector<l_l>v;
    ll pos=0;

 ll ans=0;
ll N=35;
    ll po[N];
    po[0]=1;
    rep(i,1,N-1)po[i]=po[i-1]*2;

    while(pos<=n-1){
        ll val=qq[pos];
        ll c=1;
        while(pos<=n-2&&qq[pos+1]==val){
            pos++;
            c++;
        }
        
       v.pb(l_l(val,c));

        pos++;
    }
    /*for(auto x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }*/
    ll t=v.size();


    for(int i=t-1;i>=0;i--){
        l_l qqq=v[i];
        ll val=v[i].first;
        ll c=v[i].second;

        ll q=*lower_bound(po,po+N,val);
        if(q==val){
            ll yes=c/2;
            ans+=yes;
            v[i].second-=yes*2;
        }else{
            ll res=q-val;
            ll posi=lower_bound(v.begin(),v.end(),l_l(res,0))-v.begin();
            if(v[posi].first!=res)continue;
            ll yes=max(v[posi].second,c);
            ans+=yes;
            v[i].second-=yes;
            v[posi].second-=yes;
        }

    }
    cout<<ans<<endl;
    /*for(auto x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }*/
    
    return 0;
} 