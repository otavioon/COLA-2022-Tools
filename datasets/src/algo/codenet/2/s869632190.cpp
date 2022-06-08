#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    multiset<ll> st;
    rep(i,n){
        ll a;
        cin >> a;
        st.insert(a);
    }
    int ans = 0;
    ll two = pow(2LL,31);
    rep(i,32){
        for(auto e : st){
            if(e < two) continue;
            auto p = st.find(e - two);
            if(p == st.end()) continue;
            st.erase(e);
            st.erase(p);
            ++ans;
        }
        two /= 2;
    }
    cout << ans << endl;
    return 0;
}