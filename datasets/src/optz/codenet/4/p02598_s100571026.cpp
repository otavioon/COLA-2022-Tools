#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#include <cctype>
#include <locale>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<long long,long long> Pll;
#define fout(num) cout << fixed << setprecision(20) << (num) << endl
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
//vector<vector<ll>> dp(n,vector<ll>(n))
//exist x map o setconst ll MOD = 1e9+7;return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll l=0,r=1e15;
    while(r-l>1){
        ll mid=(l+r)/2;
        int cnt=0;
        rep(i,n){
            ll x=(a[i]+mid-1)/mid;
            cnt+=(x-1);
        }
        if(cnt<=k) r=mid;
        else l=mid;
    }
    cout<<r<<endl;
    return 0;
}

