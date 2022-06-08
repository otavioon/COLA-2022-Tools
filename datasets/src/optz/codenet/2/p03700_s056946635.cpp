#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
ll INF = 1e18;

/*解説AC*/

ll n, a, b;
vector<ll>v;

bool enough(ll t){
    ll tmp = 0;
    rep(i, n){
        /*a-b-1してから割ると良い*/
        if(v[i]>t*b){
            tmp += (v[i]-t*b+(a-b)-1LL)/(a-b);
        }
    }
    if(tmp<=t) return true;
    else return false;
}
 
int main(void){
    cin>>n>>a>>b;
    v.resize(n);
    rep(i, n) cin>>v[i];
    ll left=0;
    ll right=INF;
    while((right-left)>1){
        ll mid = left + (right-left)/2;
        if(enough(mid)) right=mid;
        else left=mid;
    }
    cout<<right<<endl;
    return 0;
}