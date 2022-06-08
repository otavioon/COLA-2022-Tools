#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <functional>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ld> vld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF ((int)1e9)
#define INFLL ((ll)1e18)
#define MOD (1000000007LL)


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    multiset<int> mset;
    for (int n = 0; n < N; ++n) {
        int tmp;
        cin >> tmp;
        mset.insert(tmp);
    }
    
    int res = 0;
    while (!mset.empty()) {
        auto it = mset.end();
        --it;
        int max = *it;
        mset.erase(it);
        int x = 1;
        while (x < max) x <<= 1;
        auto it2 = mset.find(x - max);
        if (it2 != mset.end()) {
            ++res;
            mset.erase(it2);
        }
    }
    cout << res << endl;

    return 0;
}
