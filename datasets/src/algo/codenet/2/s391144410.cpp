#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;
using i64=long long int;

int main() {
    int N;
    cin >> N;
    multiset<int> A;

    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        A.insert(t);
    }

    int ans = 0;
    auto it = A.end();
    while (A.size() > 1 && --it != A.begin()) {
        int n = *it;
        A.erase(it);

        int mask = 0;
        int tmp = n;
        while (tmp) {
            tmp >>= 1;
            mask = (mask << 1) | 1;
        }
        int op = (~n & mask) + 1;

        auto opi = A.find(op);
        if (opi != A.end()) {
            ++ans;
            A.erase(opi);
        }

        it = A.end();
    }

    cout << ans << endl;

    

    return 0;
}
