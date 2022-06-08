#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,A,B;
ll h[100010];
ll binarySearch(function<bool(ll)> check, ll ok, ll ng) {
  while ((ok - ng > 1) || (ng - ok > 1)) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}
bool Check(ll n){
    ll cnt=0;
    for(ll i=0;i<N;i++){
        if(h[i]-n*B > 0){
            cnt+=(h[i]-n*B-1)/(A-B)+1;
        }
    }
    return !(cnt<=n);
}
int main(){
    cin>>N>>A>>B;
    for(ll i=0;i<N;i++){
        cin>>h[i];
    }
    cout<<binarySearch(Check,0,INF)+1<<endl;
    return 0;
}