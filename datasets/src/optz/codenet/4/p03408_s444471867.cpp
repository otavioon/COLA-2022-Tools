
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
#define int long long int
const int INF = 1001001001001001LL;
const int MOD = 1000000007;

int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

signed main(){
    
    int n; cin >> n;
    set<string> st;
    vector<string> mon(n);
    for(int i = 0; i < n; i++){
        cin >> mon[i];
        st.insert(mon[i]);
    }
    int m; cin >> m;
    vector<string> kukui(m);
    for(int i = 0; i < m; i++){
        cin >> kukui[i];
        st.insert(kukui[i]);
    }
    
    int ans = 0;
    for(auto e : st){
        int tmp = 0;
        for(auto f : mon){
            tmp += (e == f);
        }
        for(auto f : kukui){
            tmp -= (e == f);
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
