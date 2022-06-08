#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    set<int> se;
    rep(i,k) {
        int d;
        cin >> d;
        se.insert(d);
    }
    rep2(i,n,1000000) {
        string s = to_string(i);
        bool ok =  true;
        for(char c : s) {
            if(se.count(c-'0')) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << i << endl;
            return 0;
        }
    }
}
