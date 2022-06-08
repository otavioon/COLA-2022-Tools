#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

bool check(int i, set<int> &hates) {
    while (i != 0) {
        int k = i % 10;
        if (contain(hates, k)) {
            return false;
        }
        i /= 10;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    set<int> hates;
    rep(i, k) {
        int x;
        cin >> x;
        hates.insert(x);
    };
    for (int i = n; i <= n * 100; i++) {
        if (check(i, hates)) {
            cout << i << endl;
            return 0;
        }
    }

}