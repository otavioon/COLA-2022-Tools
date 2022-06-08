//********************************************************************//
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define RANGE(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define DFOR(i, a, b) for(int i = a; i > b; --i)
#define DEB(x) cout << #x << ": " << x << endl
#define ALL(v) v.begin(), v.end() 
#define SORT(v) sort(ALL(v))
#define DISPV(v) { for(auto x___: v) cout << x___ << " "; cout << endl; }
#define DISPM(m) { for(auto x____: m){ cout << x____.first << ": " << x____.second << endl; } };
#define DISPMV(m) { for(auto x_____: m){ cout << x_____.first << ": " ;DISPV(x_____.second);} };
using LL = long long;
using VI = vector <int>;
using VL = vector <long long>;
using VVI = vector<VI>;
using VVL = vector <VL>;
using MII = map<int, int>;
using MIVI = map<int, VI>;
using MLL = map<LL, LL>;
int READ_INT(){int temp;cin>>temp;return temp;}      // read an int
LL READ_LONG(){LL temp;cin>>temp;return temp;}      // read a long long

const int MOD = int(1e9) + 7;
const int INF = 1e9 + 5;
const double PI = acos(-1.0); //M_PI;
const double EPS = 1e-9;
//********************************************************************//

LL n, k;
VL rods;

LL req(long long m){
    LL ans = 0;
    for(auto v: rods){
        ans += ((v / m) - 1);
        ans += (v % m != 0);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    RANGE(i, n)
        rods.push_back(READ_LONG());
    
    LL l = 1, r = *max_element(ALL(rods)), m, ans = r;
    LL cuts_req;

    while(r - l > 1){
        m = l + (r - l)/2;
        cuts_req = req(m);
        if(cuts_req > k)
            l = m;
        else{ 
            r = m;
            ans = m;
        }
        // cout << l << ", " << r <<": " << cuts_req << endl;
    } 
    // cout << c << endl;
    // cout << l << ", " << r << endl;
    // cout << req(l) << ", " << req(r) << endl;
    // cout << cuts_req << endl;
    // cout << ceil(l) << endl;
    // cout << (LL)round(r) << endl;
    // cout << (LL)l << endl;
    // cout << r << endl;
    // cout << (LL)r << endl;
    // cout << llroundl(ans) << endl;
    // cout << (LL)ceil(ans) << endl;

    VL temp = {l, m, r, ans};
    sort(temp.rbegin(), temp.rend());
    for(auto x: temp){
        if(req(x) <= k){
            cout << x << endl;
            return 0;
        }
    }

    return 0;
}



/* complie flags
-Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
*/