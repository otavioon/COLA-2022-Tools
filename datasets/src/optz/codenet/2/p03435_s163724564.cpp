#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    vector<vector<ll>> C(3, vector<ll>(3, 0));
    for(ll i=0;i<3;++i)
        for(ll j=0;j<3;++j)cin>>C[i][j];
    bool ans=1;
    if(!(C[0][0]-C[0][1]==C[1][0]-C[1][1]&&C[1][0]-C[1][1]==C[2][0]-C[2][1]))ans=0;
    if(!(C[0][1]-C[0][2]==C[1][1]-C[1][2]&&C[1][1]-C[1][2]==C[2][1]-C[2][2]))ans=0;
    if(!(C[1][0]-C[0][0]==C[1][1]-C[0][1]&&C[1][0]-C[0][0]==C[1][2]-C[0][2]))ans=0;
    if(!(C[2][0]-C[1][0]==C[2][1]-C[1][1]&&C[2][1]-C[1][1]==C[2][2]-C[1][2]))ans=0;
    if(ans)prt("Yes")
    else prt("No")

    return 0;
}
