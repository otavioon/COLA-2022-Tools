#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e18 * 5;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N;
    multiset<string> s, t;
    set<string> ls;
    REP(i, N){
        string st;
        cin >> st;
        s.insert(st);
        ls.insert(st);
    }
    cin >> M;
    REP(i, M){
        string st;
        cin >> st;
        t.insert(st);
        ls.insert(st);
    }
    int ans = 0;
    for(auto &x: ls){
        chmax(ans, (int)s.count(x)-(int)t.count(x));
    }
    cout << ans << "\n";
    return 0;
}