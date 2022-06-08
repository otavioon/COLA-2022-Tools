#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin>>N;
    multiset<ll> m;
    rep(i,N){
        ll x;
        cin>>x;
        m.insert(x);
    }
    ll ans = 0LL;
    while(!m.empty()){
        auto ite = m.end();
        ite--;
        ll t = *ite;
        m.erase(ite);
        ll s = t;
        ll c = 1LL;
        while(s>0){
            s>>=1LL;
            c<<=1LL;
        }
        if(m.find(c-t)!=m.end()){
            ans++;
            m.erase(m.find(c-t));
        }
    }
    cout<<ans<<endl;
}