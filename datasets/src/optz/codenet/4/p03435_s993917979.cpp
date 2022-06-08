#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll c[3][3];
    rep(y,3) rep(x,3) cin >> c[x][y];

    vector<ll> a(3,0), b(3,0);

    rep(a1,c[0][0]+1){
        rep(a2, c[0][1]+1){
            rep(a3, c[0][2]+1){
                rep(b1,c[0][0]+1 - a1){
                    rep(b2, c[1][0]+1 - a1){
                        rep(b3, c[2][0]+1 - a1){
                            if(a1+b1==c[0][0] and a2+b1==c[0][1] and a3+b1==c[0][2] and
                                a1+b2==c[1][0] and a2+b2==c[1][1] and a3+b2==c[1][2] and
                                a1+b3==c[2][0] and a2+b3==c[2][1] and a3+b3==c[2][2]){
                                    put("Yes");
                                    return 0;
                                }
                        }
                    }
                }
            }
        }
    }
    put("No");
}