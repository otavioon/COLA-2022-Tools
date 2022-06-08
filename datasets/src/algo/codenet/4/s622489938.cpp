#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    EACH(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    REP(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector< vector<T> >& vec) {
    REP(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}

bool check(int N, const set<char>& S) {
    string s = to_string(N);
    EACH(c, s) {
        if (S.count(c) > 0) return false;
    }
    return true;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N, K; cin >> N >> K;
    set<char> s;
    REP(i, K) {
        char c; cin >> c;
        s.insert(c);
    }
    while ( !check(N, s) ) ++N;
    cout << N << endl;
}
