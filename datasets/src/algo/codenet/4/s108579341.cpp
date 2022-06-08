#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;
const int mod = 1e9+7;

int main() {
    int n, k; cin >> n >> k;
    set<int> st;
    rep(i,k) {
        int d; cin >> d;
        st.insert(d);
    }
    while (true) {
        int x = n;
        bool ok = true;
        while (x > 0) {
            int tmp = x % 10;
            if (st.find(tmp) != st.end()) ok = false;
            x /= 10;
        }
        if (ok) {cout << n << endl; return 0;}
        else n++;
    }
}