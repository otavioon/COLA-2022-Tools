#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,ans=0;cin>>n;
    multiset<ll> st;
    for(ll i=0,x;i<n;i++)cin>>x,st.insert(x);
    while(!st.empty()){
        auto itr= st.end();
        itr--;
        ll val = *itr;
        st.erase(itr);

        ll p=0;
        while(val >= (1ll<<p) )p++;

        ll req = (1ll<<p) - val;

        itr=st.find(req);
        if(itr==st.end())continue;

        ans++;
        st.erase(itr);
    }

    cout<<ans;
}


