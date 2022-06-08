#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int N,K;
    cin >> N >> K;
    set<int> D;
    REP(_,K) {
        int d;
        cin >> d;
        D.insert(d);
    }

    FOR(val,N,100000) {
        string s = to_string(val);
        bool ok = true;
        for(const auto &it: s) if(D.count(((int)it-'0'))) ok = false;
        if(!ok) continue;
        cout << val << endl;
        return;
    }
}

int main() {
    solve();
    return 0;
}