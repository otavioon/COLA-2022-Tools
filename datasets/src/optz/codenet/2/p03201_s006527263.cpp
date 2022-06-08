#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    set<ll> num;
    ll t = 1;
    while(t<ll(1e9)+5){
        t*=2;
        num.insert(t);
    }
    ll N;
    cin >> N;
    map<ll,ll> mp;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        mp[a]++;
    }
    ll ans =0;
    for(auto itr = mp.rbegin();itr != mp.rend();++itr){
        if(itr->second ==0){
            continue;
        }
        ll n = itr->first;
        // cerr <<"n=" << n <<" num="<< mp[n]<< endl;
        
        ll t = *num.upper_bound(n);
        t-=n;
        // cerr <<"t=" <<t << endl;
        if(mp.find(t) == mp.end()|| mp[t] ==0){
            continue;
        }
        if(n==t){
            ans += (mp[n]/2);
            mp[n] -= (mp[n]/2)*2;
        }else{
            ans++;
            mp[n]--;
            mp[t]--;
        }
       
    }
    cout << ans << endl;
    return 0;
}