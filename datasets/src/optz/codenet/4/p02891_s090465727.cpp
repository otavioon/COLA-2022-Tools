#include <stdio.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef vector<vector<int>> v2int;
typedef vector<ll> vll;
typedef vector<vector<ll>> v2ll;
typedef list<int> liint;
typedef pair<int, int> pint;
const int INF = int(2e9);
const ll LINF = ll(2e9) * ll(2e9);
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b) { a > b ? : a = b; }
template<class T, class C> void chmin(T& a, C b) { a < b ? : a = b; }



int main() {
    string S;
    cin >> S;
    ll K;
    cin >> K;
    int N = S.size();
    string S2 = S + S;
    ll ans = 0;
    int same_num = 1;
    set<char> Set;
    rep(i, S.size()) {
        Set.insert(S[i]);
    }
    if (Set.size() == 1) {
        cout << S.size() * K / 2 << endl;
        return 0;
    }
    REP(i, 0,  S2.size() - 1) {
        if (S2[i] == S2[i + 1]) {
            same_num++;
        }
        else {   
            ans += same_num / 2;
            same_num = 1;
        }
    }
    
    ans += same_num / 2;
    

    if (K % 2 == 0) {
        
        cout << ans * K / 2 << endl;
        return 0;
    }
    else {
        ans *= (K / 2);
        ans -= same_num / 2;
        int i = 0;
        while (S[i] == S2[S2.size() - 1]) {
            same_num++;
            i++;
        }
        ans += same_num / 2;
        
        same_num = 1;
        REP(j, i, S.size() - 1) {
            if (S[j] == S[j + 1]) {
                same_num++;
            }
            else {
                ans += same_num / 2;
                same_num = 1;
            }
        }
        ans += same_num / 2;
        cout << ans << endl;
        return 0;
    }
    
    return 0;
}