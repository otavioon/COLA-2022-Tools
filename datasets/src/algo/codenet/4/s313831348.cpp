#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<functional>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;

int main(){
    ll K,N;
    cin>>N>>K;
    set<ll> st;
    for(ll i=0;i<K;i++){
        ll d;
        cin>>d;
        st.insert(d);
    }
    while(1){
        string n=to_string(N);
        bool f=true;
        for(auto c:n){
            if(st.count(c-'0')==1){
                f=false;
                break;
            }
        }
        if(f){
            break;
        }
        N++;
    }
    cout<<N<<endl;
    return 0;
}