#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;

bool is_iroha(int n, set<int>& s) {
    if(n == 0) return true;
    else return s.count(n % 10) == 1 and is_iroha(n / 10, s);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    set<int> iroha_set;
    REP(i, 10) iroha_set.insert(i);
    REP(i, k) {
        int d;
        cin >> d;
        iroha_set.erase(d);
    }
    FOR(i, n, 99999)if(is_iroha(i, iroha_set)){
        cout << i << endl;
        return 0;
    }
    return 0;
}
