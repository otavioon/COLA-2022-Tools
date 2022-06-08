#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

multiset<ll> st;

int main(){
    int n, ans = 0;
    cin >> n;
    rep(i, n){
        ll a;
        cin >> a;
        st.insert(a);
    }

    while(st.size()){
        ll a = *st.rbegin();
        st.erase(st.find(a));
        ll p;
        rep(j, 30){
            if(ll(pow(2,j)>a)){
                p = ll(pow(2,j));
                break;
            }
        }
        if (st.find(p-a)!=st.end()){
            st.erase(st.find(p-a));
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
