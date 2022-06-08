#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
multiset<ll> st;
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        ll A;
        cin>>A;
        st.insert(A);
    }
    ll ans=0;
    while(!st.empty()){
        auto it=st.end();
        it--;
        ll n=*it;
        st.erase(it);
        ll a=1;
        while(a<=n)a<<=1;
        it=st.find(a-n);
        if(it!=st.end()){
            st.erase(it);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}