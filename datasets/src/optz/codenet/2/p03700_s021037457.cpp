#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

static const ll MAX=1e5+1;
ll N,A,B;
ll h[MAX];

bool enough(ll x){
    ll num=0;
    for(int i=0;i<N;i++){
        if(h[i]-B*x>0){
            num+=(h[i]-B*x+(A-B-1))/(A-B);
        }
    }
    if(num<=x) return true;
    else return false;
}

int main(){
    cin >> N >> A >> B;
    ll mx=0;
    for(int i=0;i<N;i++){
        cin >> h[i];
        mx=max(mx,h[i]);
    }
    ll left=0;
    ll right=mx+1;
    while(right-left>0){
        ll mid=(left+right)/2;
        if(enough(mid)){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    cout << right << endl;
}
