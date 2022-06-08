#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#ifdef RUBICK
#include "dbg.h"
#endif

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    set<int> forbidden;
    while (k--) {
        int x;
        scanf("%d", &x);
        forbidden.insert(x);
    }

    const auto disliked = [&](int x) {
        while (x > 0) {
            int d = x % 10;
            x /= 10;

            if (forbidden.count(d) == 1)
                return true;
        }

        return false;
    };

    while (disliked(n))
        n ++;

    printf("%d\n", n);

    return 0;
}

