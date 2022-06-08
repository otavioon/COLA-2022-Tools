#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

typedef pair<ll, ll> P;

void print_line(vector<vector<int>> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        for (int y = 0; y < ans[i].size(); y++) {
            cout << ans[i][y];
        }
        cout << endl;
    }
}

struct RangeCount {
    int upper, r_equal, between, l_equal, lower;

    friend std::ostream &operator<<(std::ostream &out, const RangeCount &o) {
        cout << endl;
        cout << "upper" << ' ' << o.upper << endl;
        cout << "r_equal" << ' ' << o.r_equal << endl;
        cout << "between" << ' ' << o.between << endl;
        cout << "l_equal" << ' ' << o.l_equal << endl;
        cout << "lower" << ' ' << o.lower << endl;
        return out;
    }
};


// startは含む
// endは含まない
RangeCount range_count(vector<int>::iterator start, vector<int>::iterator end, int l, int r) {
    if (l > r) return RangeCount{0, 0, 0, 0, 0};
    if (start >= end) return RangeCount{0, 0, 0, 0, 0};

    if (l == r) {
        RangeCount rc;
        auto it_u = upper_bound(start, end, r);
        auto it_l = lower_bound(start, end, r);

        rc.upper = distance(it_u, end);
        rc.r_equal = distance(it_l, it_u);
        rc.between = 0;
        rc.l_equal = rc.r_equal;
        rc.lower = distance(start, it_l);

        return rc;
    }

    RangeCount rc;
    auto it_ru = upper_bound(start, end, r);
    auto it_rl = lower_bound(start, end, r);
    rc.upper = distance(it_ru, end);
    rc.r_equal = distance(it_rl, it_ru);
    auto it_lu = upper_bound(start, end, l);
    auto it_ll = lower_bound(start, end, l);
    rc.between = distance(it_lu, it_rl);
    rc.l_equal = distance(it_ll, it_lu);
    rc.lower = distance(start, it_ll);

    return rc;

}


int main() {

    int n;
    cin >> n;
    vector<int> edges(n);
    rep(i, n) cin >> edges[i];
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = edges[i], b = edges[j];

            RangeCount rc = range_count(edges.begin() + j + 1, edges.end(), b - a, b + a);

            ans += rc.between;
        }
    }
    cout << ans << endl;

}