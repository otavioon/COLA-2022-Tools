#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,a;
multiset<ll,greater<ll>>st;
map<ll,ll>mp;

int main(){
    cin>>n;
    rep(i,n){
        cin>>a;
        st.insert(a);
    }
    ll ans=0;
    while(!st.empty()){
        ll b=*st.begin(),x=1;
        while(x<=b)x<<=2;
        st.erase(st.begin());
        if(st.find(x-b)!=st.end()){
            st.erase(st.find(x-b));
            ans++;
        }
    }
    cout<<ans<<endl;
}