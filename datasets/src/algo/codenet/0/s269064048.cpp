#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int32 k;
    cin >> k;
    int32 n = s.size();
    int32 cnt[2] = {0,1};
    bool flg = false;
    FOR(i,1,n){
        if(s[i-1] == s[i]){
            ++cnt[0];
            if(i == n-1)flg = true;
            ++i;
        }
    }
    if(flg || s[0] != s[n-1]){
        ANS(cnt[0] * k);
        return 0;
    }
    bool flg2 = false;
    FOR(i,2,n){
        if(s[i-1] == s[i]){
            ++cnt[1];
            if(i == n-1)flg2= true;
            ++i;
        }

    }
    if(flg2){
        ANS((k+1)/2 * cnt[0] + k/2 * cnt[1]);
    }else{
        ANS(cnt[0] + (k-1) * cnt[1]);
    }
    return 0;
}
