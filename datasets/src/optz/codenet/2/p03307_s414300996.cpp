#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using ll = long long;
 
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define reps(i,x) for(ll i=1;i<=(ll)(x);i++)
#define rrep(i,x) for(ll i=((ll)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=(ll)(x);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define mod 1000000007 
using namespace std;
int a[200005];
ll dp[200005];
ll b[4];
int main() {
    int n;
    cin >> n;
    rep(i , n)
        cin >> a[i];
    dp[0] = a[0];
    reps(i, n-1){
        dp[i] = dp[i-1] + a[i];
    }
    ll ans = 1 << 30;
    int lf, rt;
    lf = 0;
    rt = 2;
    for(int i = 2; i < n-2; i++){
        ll lmn = 1 << 30;
        ll rmn = 1 << 30;
        for(int j = lf; j < i - 1; j++){
            if(lmn >= abs(dp[j] -abs(dp[i-1] - dp[j]))){
                b[0] = dp[j];
                b[1] = dp[i-1] -dp[j];
                lmn =abs(dp[j] -abs(dp[i-1] - dp[j]));
                lf = j;
            }else{break;}
        }
        for(int j = rt; j < n - 1; j++){
            if(rmn >= abs(abs(dp[j] - dp[i-1]) -abs(dp[n-1] - dp[j]))){
                b[2] = dp[j] - dp[i-1];
                b[3] = dp[n-1] - dp[j];
                rmn = abs(abs(dp[j] - dp[i-1]) -abs(dp[n-1] - dp[j]));
                rt  = j;
            }else{break;}
        }
        sort(b, b+4);
        ans = min(ans, b[3] - b[0]);
    }
    cout << ans << endl;
}