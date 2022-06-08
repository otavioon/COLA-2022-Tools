#include<bits/stdc++.h>
#define lol(i,n) for(int i=0;i<n;i++)
typedef long long ll;

using namespace std;
int main(){
    ll n; cin>>n;
    multiset<ll> S;
    lol(i,n){
	ll a;cin>>a;
	S.insert(a);
    }
    ll ans=0;
    while(S.size()>=2){
	auto i=--S.end();
	ll x=*i;
	S.erase(i);
	ll t; for(t=1;t<=x;t*=2);
	auto j=S.find(t-x);
	if(j!=S.end()){
	    ans++;
	    S.erase(j);
	}
    }
    cout<<ans<<endl;
    return 0;
}
