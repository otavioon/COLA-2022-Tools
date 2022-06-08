#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long int;

int main() {
    // Input
    int N, K;
    vector<short> D;

    cin >> N >> K;
    D = vector<short>(K);
    rep(i, K) cin >> D[i];

    // Process
    int idx = 0;
    vector<int> allow;
    rep(i, 10) {
        if (i == D[idx])
            idx++;
        else
            allow.emplace_back(i);
    }

    vector<int> allow_nums;
    int before_size = 0;
    rep(i, 4) {
        if (i == 0) {
            for (int n : allow) allow_nums.emplace_back(n);
        } else {
            const int size = allow_nums.size();
            for (int j = before_size; j < size; j++) {
                if (allow_nums[j] == 0) continue;

                for (int n : allow)
                    allow_nums.emplace_back(allow_nums[j] * 10 + n);
            }
            before_size = size;
        }
    }

    int ans = *lower_bound(allow_nums.begin(), allow_nums.end(), N);

    // Output
    cout << ans << endl;

    return 0;
}
