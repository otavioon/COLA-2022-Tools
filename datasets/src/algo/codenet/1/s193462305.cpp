#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll c[3][3];
    ll sum=0;
    rep(i,3)rep(j,3){
        cin>>c[i][j];
        sum+=c[i][j];
    }
    ll dia=0;
    rep(i,3) dia+=c[i][i];
    if(sum==3*dia) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}