//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s; cin>>s;
    ll k,n=s.size(); cin>>k;
    vector<pair<char,ll>> c;
    ll cnt=1;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            c.push_back(mk(s[i],cnt));
            cnt=1;
        }
        else cnt++;
    }
    c.push_back(mk(s.back(),cnt));
    if(c.size()==1){
        cout<<k*n/2<<endl;
        return 0;
    }
    if(s[1]==s.back()){
        ll ans=0;
        for(int i=1;i<c.size()-1;i++)
        ans+=c[i].second/2;
        ans*=k;
        ans+=c[0].second/2+c.back().second/2;
        ans+=(c[0].second+c.back().second)/2*(k-1);
        cout<<ans<<endl;
    }
    else{
        ll ans=0;
        for(auto q:c) ans+=q.second/2;
        cout<<ans*k<<endl;
    }
}
