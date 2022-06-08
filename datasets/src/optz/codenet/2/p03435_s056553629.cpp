#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,N) for(ll i=0;i<N;i++)
typedef long long int ll;
using namespace std;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;

void calc(vvl v){
    ll a2,a3,b1,b2,b3;  
    rep(a1,v[0][0]+1){
        b1=v[0][0]-a1;
        b2=v[0][1]-a1;
        b3=v[0][2]-a1;
        a2=v[1][0]-b1;
        a3=v[2][0]-b1;
        if(b1<0 or b2<0 or b3<0 or a2<0 or a3<0){
            continue;
        }
        if(a2==v[1][1]-b2 && a2==v[1][2]-b3){
            if(a3==v[2][1]-b2 && a3==v[2][2]-b3){
                cout<<"Yes"<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;
}

int main(){
    vvl v(3,vl(3));
    rep(i,3){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    calc(v);         

    return 0;
}