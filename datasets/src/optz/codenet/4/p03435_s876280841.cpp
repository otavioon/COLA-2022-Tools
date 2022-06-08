#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main(void) {
    vector<int> cs(9);
    for (int i = 0; i < 9; i++) {
        cin >> cs[i];
    }

    for (int b1 = 0; b1 <= 100; b1++) {
        for (int b2 = 0; b2 <= 100; b2++) {
            for (int b3 = 0; b3 <= 100; b3++) {
                vector<int> bs = {b1, b2, b3};
                vector<set<int>> cand_as(3);
                // set<int> cand_a1, cand_a2, cand_a3;
                for (int i = 0; i < 9; i++) {
                    cand_as[i % 3].insert(cs[i] - bs[i / 3]);
                }

                bool ok = true;
                for (auto as : cand_as) {
                    if ((int) as.size() != 1 || *as.begin() < 0 || *as.begin() > 100) {
                        ok = false;
                    }
                }
                if (ok) {
                    // printf("a1: %d, a2: %d, a3: %d, b1: %d, b2: %d, b3: %d\n",
                    //         *cand_as[0].begin(), *cand_as[1].begin(), *cand_as[2].begin(),
                    //         b1, b2, b3);
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
