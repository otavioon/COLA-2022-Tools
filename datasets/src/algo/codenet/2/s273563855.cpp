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
    for(auto i=st.rbegin();i!=st.rend();i++){
        ll n=0;
        while((1<<n) <= *i)n++;
        auto it=st.lower_bound((1<<n)-*i);
        if(it!=st.end() && *i+*it==(1<<n)){
            ans++;
            st.erase(it);
            auto tmp=i;
            st.erase((++tmp).base());
            i--;
        }
        // for(auto j=st.rbegin();j!=st.rend();j++){
        //     cout<<*j<<" ";
        // }cout<<endl;
    }
    cout<<ans;
    return 0;
}