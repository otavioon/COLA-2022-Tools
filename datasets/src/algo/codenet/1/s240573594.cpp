//AtCoder ABC088 C - Takahashi's Information
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll ctbl[3][3];
    ll ttl=0;
    for(ll y=0;y<3;++y){
        for(ll x=0;x<3;++x){
            ll c;
            cin>>c;
            ctbl[y][x]=c;
            ttl+=c;
        }
    }
    bool ans=(ttl%3==0);
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}